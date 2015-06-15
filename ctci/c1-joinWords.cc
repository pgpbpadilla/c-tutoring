#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

string joinWordsCopy(vector<string> words);
string joinWordsWithBuffer(vector<string> words);
string joinWordsWithStringStream(vector<string> words);

int main () {
  string words[] =  {"one", "two", "three", "four", "five", 
                            "six", "seven", "eight", "nine", "ten"};
  vector<string> wv;

  for (int i = 0; i < 10000; ++i) {
    wv.push_back(words[i%10]);
  }

  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  cout<< "Joining words by copying ...";
  joinWordsCopy(wv);
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(t2-t1);
  cout<< "Run time: " << duration.count() << " microseconds" << endl;

  t1 = high_resolution_clock::now();
  cout<< "Joining words by appending ...";
  joinWordsWithBuffer(wv);
  t2 = high_resolution_clock::now();
  duration = chrono::duration_cast<chrono::microseconds>(t2-t1);
  cout<< "Run time: " << duration.count() << " microseconds" << endl;


  t1 = high_resolution_clock::now();
  cout<< "Joining words with StringStream ...";
  joinWordsWithStringStream(wv);
  t2 = high_resolution_clock::now();
  duration = chrono::duration_cast<chrono::microseconds>(t2-t1);
  cout<< "Run time: " << duration.count() << " microseconds" << endl;

}

string joinWordsCopy(vector<string> words) {
  string result = "";

  for(string word: words) {
    result += word;
  }
  return result;
}

string joinWordsWithBuffer(vector<string> words) {

  string result;

  for(string word: words) {
    result.append(word);
  }
  
  return result;
}

string joinWordsWithStringStream(vector<string> words) {
  stringstream result;

  for(string word: words) {
    result << word;
  }

  return result.str();
}
