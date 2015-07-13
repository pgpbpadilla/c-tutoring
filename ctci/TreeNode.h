#include <string>
#include <vector>

using namespace std;

enum class TraversalType: int { InOrder };

class TreeNode {

public:

  TreeNode* parent;
  TreeNode* left;
  TreeNode* right;
  int data;

  TreeNode(int value);
  TreeNode(vector<int> numbers);
  ~TreeNode();
  TreeNode* getNext(TreeNode* node);
  string toString(TraversalType traversalType = TraversalType::InOrder);

private:
  TreeNode* buildTree(vector<int> numbers, int start, int end);
  string stringFromTreeInOrder(TreeNode* node);
};
