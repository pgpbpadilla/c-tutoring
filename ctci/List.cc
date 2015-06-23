#include "List.h"
#include <iostream>
#include <string>

using namespace std;

Node::Node(int value) :data{value} {
  next = nullptr;
}

string Node::toString () {
  Node *current = this;
  string result = to_string(current->data) + " ";

  while (nullptr != current->next) {
    result += to_string(current->next->data) + " ";
    current = current->next;
  }

  return result;
}

List::List() {
  head = nullptr;
}

void List::add(int data) {
  Node* last = new Node(data);
  Node* current = head;

  cout<< "Created new node for data: " << data << endl;
  
  if (nullptr == head) {
    head = last;
    return;
  }

  while (nullptr != current->next){
    // cout<< "current->data = " << current->data << endl;
    // cout<< "current->next->data = " << current->next->data << endl;
    current = current->next;
  }

  current->next = last;
}

void List::remove(int data){
  Node* toDelete = nullptr;

  // delete head node
  if (head->data == data) {
    toDelete = head;
    head = head->next;
    return;
  }

  Node* current = head;
  // keep going until you find the element
  // to delete
  while(current->next->data != data) {
    current = current->next;
  }
  toDelete = current->next;

  current->next = toDelete->next;
  return;
}

string List::toString() {
  return head->toString();
}
