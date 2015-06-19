#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> aVector) {
  for (auto i : aVector) {
    cout << i << " " ;
  }
  cout << endl;
}

vector<int> parseArguments(int count, char* arguments[]) {
  vector<int> input;
  // start in 1 since 0 is the name of the program
  for (int i = 1; i < count; ++i ){
    input.push_back(atoi(arguments[i]));
  }
  cout<< "Input vector: " << endl;
  printVector(input);
  return input;
}

int productFromVector(vector<int> aVector) {
  int total = 1;
  for (auto i : aVector) {
    total *= i;
  }
  cout << "Total: " << total << endl;

  return total;
}


int main (int argc, char* argv[]) {
  
  if (2 > argc) {
    cout<< "Not enough arguments" << endl;
    cout<< "Usage example: $ <cmd> 1 2 3 4 5" << endl;

    return -1;
  }

  vector<int> input;
  input = parseArguments(argc, argv);

  int total = productFromVector(input);

  vector<int> result;
  for (auto i : input) {
    // To calculate the product of all the elements in the array
    // except the current one just divide the total product by the 
    // current element in the array.
    // This works because: 
    //   total = i1 * ... * ik * ... * iN
    // and the product for element ik is:
    //   product(ik) = i1 * ... * iN = total / ik
    result.push_back(total/i);
  }

  printVector(result);
  
  return 0;
}
