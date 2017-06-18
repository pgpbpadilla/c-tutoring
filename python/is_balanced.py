import sys

input = sys.argv[1]

print('Input: {}'.format(input))

stack = []

for c in input:
    print('processing {}'.format(c))

    if c == '(':
        stack.append(c)
        print('push {}'.format(c))
    elif c == ')' and len(stack) > 0:
        pc = stack.pop()
        print('pop {}'.format(pc))
    else:
        sys.exit('Unbalanced')

    print('stack: {}'.format(stack))
    
if len(stack) > 0:
    sys.exit('Unbalanced')

print('Balanced!, Yay!')

