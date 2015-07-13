#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "TreeNode.h"

using namespace std;

int main(int argc, char* argv[]) {

  vector<int> numbers;

  if (argc < 2) {
    cout<< "You must pass a sorted list of integers" << endl;
    cout<< "Usage: $ program [<int> <int> ...]" << endl;
    return -1;
  }

  for (int i = 1; i < argc; ++i) {
    numbers.push_back(atoi(argv[i]));
  }

  try {

    TreeNode* root = new TreeNode(numbers);
    
    cout << root->serialize() << endl;
  
    for (auto v: numbers) {
      cout << "getNext(" << v << "): " << root->getNext(v) << endl;
    }

  } catch (const invalid_argument& e) {
    cout << e.what() << endl;
  }

  return 0;
}
