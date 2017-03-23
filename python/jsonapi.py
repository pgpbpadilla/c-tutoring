from marshmallow_jsonapi import Schema, fields

class CommentSchema(Schema):
    # def __init__(self, prefix, *args, **kwargs):
    #     super(CommentSchema, self).__init__(self, *args, **kwargs)
    #     self.prefix = prefix
    
    id = fields.Str()
    content = fields.Str()
    
    class Meta:
        type_ = 'comments'
        strict = True


class PostSchema(Schema):
    def __init__(self, prefix, *args, **kwargs):
        super(PostSchema, self).__init__(*args, **kwargs)
        self.prefix = prefix

    id = fields.Str(dump_only=True)
    title = fields.Str()
    comments = fields.Relationship(
        include_resource_linkage=True,
        type_='comments',
        schema=CommentSchema
    )
#    comments = fields.Method('make_relationship')

    def make_relationship(self, obj):
        return fields.Relationship(
            include_resource_linkage=True,
            type_ = 'comments',
            schema=CommentSchema(self.prefix)
        )
    
    class Meta:
        type_ = 'posts'
        strict = True


from collections import namedtuple
import json


class Model(object):
    def __init__(self, **kwargs):
        for k, v in kwargs.iteritems():
            setattr(self, k, v)


post = Model(id=123, title='something', comments=Model(id=123, content='blah'))

#print PostSchema().dump(post).data
data, errors = PostSchema('prefix').dump(post)

print json.dumps(data, indent=4)
