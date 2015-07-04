#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class TraversalType: int { InOrder };

class TreeNode {

public:

  TreeNode* parent;
  TreeNode* left;
  TreeNode* right;
  int data;

  TreeNode(int value): data {value} {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }

  ~TreeNode() {
    // if the pointers are `nullptr` then
    // deleting them is harmless
    delete parent;
    delete left;
    delete right;
  }

  string stringFromTreeInOrder(TreeNode* node) {
    string result = "";
    // TODO: review tree traversal methods
    return result;
  }

  string toString(TreeNode* node = nullptr, TraversalType traversalType = TraversalType::InOrder){
    
    TreeNode* root = nullptr == node ? this : node;

    switch (traversalType) {
    default:
      return this->stringFromTreeInOrder(node);
    }

    return "Error trying to create string from node";
  }

};

TreeNode* buildTree(vector<int> numbers, int start, int end) {
  cout<< "start: " << start << "; end: " << end << endl;
  if  (end < start) {
    return nullptr;
  }
  
  int midPoint = (end + start) / 2;
  cout << "midPoint: " << midPoint << endl;

  TreeNode* root = new TreeNode(numbers[midPoint]);
  cout<< "root:" << root->data << endl;

  root->left = buildTree(numbers, start, midPoint - 1);
  root->right = buildTree(numbers, midPoint + 1, end);

  return root;
}

int main(int argc, char* argv[]) {

  vector<int> numbers;

  if (argc < 2) {
    cout<< "You must pass a list of integers" << endl;
    cout<< "Usage: $ program <int> [<int> <int> ...]" << endl;
    return -1;
  }

  for (int i = 1; i < argc; ++i) {
    numbers.push_back(atoi(argv[i]));
  }

  for (int n: numbers) {
    cout<< n << " " ;
  }
  cout << endl;
  
  TreeNode* root = buildTree(numbers, 0, numbers.size()-1);
  
  return 0;
}
