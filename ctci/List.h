#include <string>

using namespace std;

class Node {
  public:
  
  Node* next;
  int data;

  Node(int value);
  string toString();
};

class List {

 public:
  Node* head;
  List();
  void add(int data);
  void remove(int data);
  string toString();
};
