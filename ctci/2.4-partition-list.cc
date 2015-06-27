#include "List.h"
#include <iostream>

using namespace std;

void partition(List aList, int value);

int main(int argc, char* argv[]) {

  List list;
  
  if (3 > argc) {
    cout<<"Usage: ./xxx <pivot> <int> [<int> <int> ...]"<< endl;
    cout<<"E.g.: ./xxx 2 3 1"<< endl;
    return -1;
  }

  for(int i = 2; i< argc; ++i) {
    list.add(atoi(argv[i]));
  }

  partition(list, atoi(argv[1]));

  cout << "Paritioned list: " << list.toString() << endl;

  return 0;
}

void partition(List aList, int value) {
  // will partition `aList` such that all nodes with values < `value` are before 
  // all nodes with values >= `value`

  cout<< "Will partition list around: " << value << endl;

  if (nullptr == aList.head 
      || nullptr == aList.head->next) {
    cout<<"Nothing to to->"<<endl;
    cout<<"List: " << aList.toString() << endl;
    return;
  }

  Node* current = aList.head;
  Node* greaterThanOrEqual = nullptr;
  Node* lastAdded = nullptr;

  while (nullptr != current->next) {
    cout<< "current: " << current->data << endl;

    if (current->data >= value) { // node greater than value

      if (nullptr == greaterThanOrEqual) { // first node >= than value
        // create a secondary list for all nodes greater than or equal than value
        greaterThanOrEqual = new Node(current->data);
        lastAdded = greaterThanOrEqual; // keep a pointer to the last element added

      } else if (current->data == value) { // add node at the begining of the list

        // make sure nodes equal to value are at the begining of the secondary list
        Node *tmp = new Node(current->data);
        tmp->next = greaterThanOrEqual; // make new node the head of the list
        greaterThanOrEqual = tmp;
        tmp = nullptr;

      } else { // add node at the end of the list

        lastAdded->next = new Node(current->data);
        lastAdded = lastAdded->next;

      }

      cout<<"greaterThanOrEqual: " << greaterThanOrEqual->toString() << endl;
      
      // remove from the list
      cout<<"remove current: "<< current->data << endl;
      current->data = current->next->data;
      current->next = current->next->next;

    } else { // Leave nodes less than value alone

      current = current->next;

    }

    cout<<"list:" << aList.toString() << endl;
  }

  // append all nodes greater than value to the end of the list
  current->next = greaterThanOrEqual;
}
