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
    // cout<< "string for node:" << node->data << endl;

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

    // cout<< "toString: " << endl;

    switch (traversalType) {
    default:
      {
        // cout << "traversal: InOrder" << endl;
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

  if (nullptr != root->left) {
    root->left->parent = root;
  }

  if (nullptr != root->right) {
    root->right->parent = root;
  }

  return root;
}

TreeNode* getNext(TreeNode* node) {
  TreeNode * next = nullptr;

  cout << "getNext: " << node->data << endl;

  if (node->right != nullptr) {

    cout << "try on the right subtree" << endl;
    next = node->right;
    
    while (nullptr != next->left) {
      cout << "go left from: " << next->data  << endl;
      next = next->left;
    }
    
    return next;
    
  } else { // there is no right child node

    cout << "try looking up" << endl;
    // start the search in the parent node
    next = node->parent;

    // if this is the root node
    // then there's no greater node
    if (nullptr == next) {
      cout << "reached null" << next << endl;
      return nullptr;
    }
    
    // this is not the root node
    // keep going up until you find the root or a node
    // that's greater than the given node
    while (nullptr != next
           && next->data < node->data) {
      cout << "go up: " << next->data << endl;
      next = next->parent;
    }
    
    // return the first parent node
    // that is greater than the given node
    cout << "next found: " << (nullptr == next ? -1 : next->data) << endl;
    return next;
  }
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
  
  TreeNode* next = getNext(root);

  if (nullptr != next) {
    cout << next->data << endl;
  }
  
  // cout<< root->left->data << endl;
  // cout<< root->right->data << endl;

  next = getNext(root->left->left->right);
  if (nullptr != next) {
    cout << next->data << endl;
  }  

  return 0;
}
