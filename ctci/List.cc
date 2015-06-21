#include <iostream>
#include <string>

using namespace std;

class Node {

public:

  Node* next = nullptr;
  int data;
  Node(int value) :data{value} {}
  string toString () {
    Node *current = this;
    string result = to_string(current->data) + " ";

    while (nullptr != current->next) {
      result += to_string(current->next->data) + " ";
      current = current->next;
    }

    return result;
  }

};

class List {
  
public:
  Node* head;

  void add(Node* n) {
    Node* last = n;
    Node* current = head;

    while (nullptr != current->next){
      current = current->next;
    }

    current->next = last;
  }

  void remove(Node* n){
    Node* toDelete = nullptr;

    if (head == n) {
      toDelete = head;
      head = head->next;
      delete toDelete;
    }

    Node* current = head;
    while(current->next->data != n->data) {
      current = current->next;
    }
    toDelete = current->next;

    current->next = toDelete->next;
    delete toDelete;
  }

  string toString() {
    return head->toString();
  }
};
