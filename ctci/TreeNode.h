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
  int getNext(int value);
  string toString(TraversalType traversalType = TraversalType::InOrder);
  string serialize();
  TreeNode* find(int value);
  
private:
  bool isSorted(vector<int> numbers);
  string serialize(TreeNode* node, int level = 0);
  TreeNode* buildTree(vector<int> numbers, int start, int end);
  string stringFromTreeInOrder(TreeNode* node);
};
