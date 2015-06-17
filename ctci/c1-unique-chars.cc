#include <iostream>
#include <map>
#include <chrono>


using namespace std;
using namespace chrono;

enum class ComparisonType: int { CTMap, CTNone };

string formatComparisonType(ComparisonType type) {

  switch(type) {
    
  case ComparisonType::CTMap: 
    return "map";
  case ComparisonType::CTNone: 
    return "none";

  }
}

bool hasAllUnique(string input) {
  // - assumption: the input string will only have characters from lowercase a-z

  map<char, int> charFrequencies;
  map<char, int>::iterator it;

  for(char& c: input) {
    it = charFrequencies.find(c);
    if (it != charFrequencies.end()){ // key found
      // this means this is the second time
      // we see this char
      cout<< "Found duplicate letter: " << c << endl;
      cout<< "Quitting..." << endl;
      return false;
    }
    // key not found, add it to the map
    charFrequencies[c] = 1;
  }

  return true;
}

bool hasAllUnique_No_Maps(string input) {
  
  for(string::size_type i = 0; i < input.size(); ++i) {
    for (string::size_type j = 0; j < input.size(); ++j) {

      if (i == j) {
        continue; // skip the letters we know to be the same
      }

      if (input[i] == input[j]) {
        cout << "Found duplicate letter: " << input[i] << endl;
        return false; //
      }
      
      continue;
    }
  }
  return true;
}

bool checkString(string input, ComparisonType type = ComparisonType::CTNone) {
  bool result;

  cout << "Checking string: " << input << endl;
  cout << "String length: " << input.length() << endl;

  if (26 != input.length()) {
    cout << "String doesn't meet the required length: " << input.length() << endl;
    return false;
  }
  
  if (ComparisonType::CTMap == type) {
    return hasAllUnique(input);
  } 
  
  return hasAllUnique_No_Maps(input);
}

int main(int argc, char* argv[]) {
  
  cout << "Arguments: " << endl;
  for (int i = 0; i<argc; ++i){
    cout<< argv[i] << endl;
  }
  
  if (2 > argc) {
    cout << "Not enough arguments, please pass an input string to check" << endl;
    cout << "Usage: $ ./<cmd> <string to check> [<comparison type>]" << endl;
    cout << "Comparison types: `map`" << endl;
    return -1;
  }
  
  bool result;

  // First argument is the string to check
  string userInput;
  high_resolution_clock::time_point t1;
  high_resolution_clock::time_point t2;
  microseconds duration;

  if (2 == argc) {
    userInput = string(argv[1]);
    t1 = high_resolution_clock::now();
    result = checkString(userInput);
    t2 = high_resolution_clock::now();
  }

  // Second argumen is the type of comparison to make, possible values:
  // - `map` - uses a map to register character frequencies
  string comparisonType;
  if (3 == argc) {
    userInput = string(argv[1]);
    comparisonType = string(argv[2]);
    
    if (formatComparisonType(ComparisonType::CTMap) != comparisonType) {
      cout << "Invalid comparison type: " << comparisonType << endl;
      return -1;
    }
    t1 = high_resolution_clock::now();
    result = checkString(userInput, ComparisonType::CTMap);
    t2 = high_resolution_clock::now();
  }
  
  cout<< "Has all unique: ";
  cout<< boolalpha << result << endl;

  duration = chrono::duration_cast<chrono::microseconds>(t2-t1);
  cout << "==========================" << endl;
  cout<< "Run time: " << duration.count() << "microseconds" << endl;
  cout << "==========================" << endl;

  return 0;
}
