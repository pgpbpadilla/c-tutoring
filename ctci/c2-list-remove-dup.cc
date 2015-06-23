#include <iostream>
#include "List.h"

#include <map>
#include <set>

using namespace std;

void printMap(map<int, bool> aMap) {
  for(auto t: aMap) {
    cout<< "[" << t.first 
        << " : " << t.second 
        << endl;
  }
}

void removeDuplicateWithFoundMap(List aList) {
  cout<< "Removing duplicates..." << endl;

  map<int, bool> found;
  map<int, bool>::iterator it;

  Node* current = aList.head;

  found[current->data] = true;

  while (nullptr != current->next) {
    cout<< "current->next->data: " << current->next->data << endl;

    it = found.find(current->next->data);
    // element already found in the list
    if (found.end() != it) {
      Node* toDelete = current->next;
      cout<< "Deleting: " << toDelete->data << endl;
      current->next = toDelete->next;

      continue;
    }

    // element not yet found in the list
    found[current->next->data] = true;
    cout<< "Added: " << current->next->data << endl;

    current = current->next;
  }
}

int main(int argc, char* argv[]) {
  List list;

  cout<< "New List created" << endl;

  for(int i = 1; i< argc; ++i) {
    cout<< "Converting :" << argv[i] << endl;
    list.add(atoi(argv[i]));
  }

  cout<< list.toString() << endl;

  removeDuplicateWithFoundMap(list);
  
  cout<< list.toString() << endl;

  return 0;
}
