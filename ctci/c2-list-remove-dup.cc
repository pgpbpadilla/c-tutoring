#include <iostream>

class List;

using namespace std;

int main(int argc, char* argv[]) {
  List list;

  for(int i = 1; i< argc; ++i) {
    list.add(atoi(argv[i]));
  }

  cout<< list.toString() << endl;

  return 0;
}
