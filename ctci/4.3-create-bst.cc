#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
    
    if (nullptr == node) {
      // cout << "emtpy string" << endl;
      return "";
    }

    stringstream result;    
    
    TreeNode* l = node;
    cout<< "string for node:" << node->data << endl;

    // cout << "go left" << endl;
    result << this->stringFromTreeInOrder(l->left) << " ";
    // cout << "current" << endl;
    result << l->data << " ";
    // cout << "go right" << endl;
    result << this->stringFromTreeInOrder(l->right);

    // cout << "result: " << result.str() << endl;
    return result.str();
  }

  string toString(TraversalType traversalType = TraversalType::InOrder){

    cout<< "toString: " << endl;

    switch (traversalType) {
    default:
      {
        cout << "traversal: InOrder" << endl;
        return this->stringFromTreeInOrder(this);
      }
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
  // cout << "midPoint: " << midPoint << endl;

  TreeNode* root = new TreeNode(numbers[midPoint]);
  // cout<< "root:" << root->data << endl;

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

  cout << "tree root: " << (nullptr == root ? -1 : root->data) << endl;
  cout << root->toString() << endl;
  
  return 0;
}
