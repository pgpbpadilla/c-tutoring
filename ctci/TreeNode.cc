#include "TreeNode.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

TreeNode::TreeNode(int value): data {value} {
  parent = nullptr;
  left = nullptr;
  right = nullptr;
}

TreeNode::TreeNode(vector<int> numbers) {

  if (false == isSorted(numbers)) {
    throw invalid_argument("The array is not sorted");
  }

  TreeNode* root = buildTree(numbers, 0, numbers.size()-1);

  data = root->data;
  parent = nullptr;
  left = root->left;
  right = root->right;
}


TreeNode::~TreeNode() {
  // if the pointers are `nullptr` then
  // deleting them is harmless
  delete parent;
  delete left;
  delete right;
}

TreeNode* TreeNode::buildTree(vector<int> numbers, int start, int end) {
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

string TreeNode::stringFromTreeInOrder(TreeNode* node) {
    
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

string TreeNode::toString(TraversalType traversalType){

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

TreeNode* TreeNode::getNext(TreeNode* node) {

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

string TreeNode::serialize() {
  return serialize(this, 0);
}

string TreeNode::serialize(TreeNode* node, int level) {

  if (nullptr == node) {
    return "";
  }

  stringstream result;
  
  result << string(level, '|') << node->data << endl;
  result << serialize(node->left, level + 1);
  result << serialize(node->right, level + 1);

  return result.str();
}

bool TreeNode::isSorted(vector<int> numbers) {

  for(int k = 1; k < numbers.size(); ++k) {
    if (numbers[k] < numbers[k-1]) {
      return false;
    }
  }

  return true;
}
