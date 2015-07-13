#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "TreeNode.h"

using namespace std;

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
  
  TreeNode* root = new TreeNode(numbers);

  cout << "tree root: " << (nullptr == root ? -1 : root->data) << endl;
  cout << root->toString() << endl;

  return 0;
}
