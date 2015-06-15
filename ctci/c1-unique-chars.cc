#include <iostream>
#include <map>

using namespace std;

bool hasAllUnique(string input) {
  // - assumption: the string is an ASCII string, that is there are 128 chars
  // - assumption: the input string will only have characters from lowercase a-z

  if (26 != input.length()) {
    return false;
  }

  //  strcpy(letters, input.c_str());

  // if you find a duplicate, then return false
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

int main(int argc, char* argv[]) {

  for (int i = 0; i<argc; ++i){
    cout<< argv[i] << endl;
  }

  if (2 == argc) {
    string userInput(argv[1]);
    bool result = hasAllUnique(userInput);
    cout<< "Has all unique: ";
    cout<< boolalpha << result << endl;
  }
}
