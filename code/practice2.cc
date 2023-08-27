#include<iostream>

// this is me practicing linked lists again while explaining it to myself.

struct Node {
  int data;
  Node* next;
};

Node* head = nullptr; // since the default is an empty list with no nodes
void Traverse() {
  Node* current = head;
  while (current != nullptr) {
    current = current->next;
  }
}

void InsertAtBegin(int value) {
  // i start by creating a new node and allocating in the heap
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = head;
  head = new_node;
}

void InsertAtEnd(int value) {
  // things i notice when i visualized it on paper
  /*
    we want to start by creating a new node. We want to go through the whole list until we reach the last node where it points at
    nullptr. We make the last node point at the node we want to insert. Then we make the node we inserted point at nullptr.
  */
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = nullptr;

  // i need to make sure that if the head is nullptr then we set the head to the new node
  if (head == nullptr) {
    head = new_node;
    return;
  }

  Node* current = head;
  while (current != nullptr) {
    current = current->next;
  }
  current->next = new_node; // so now the last node points at the new node we are inserting
}

void InsertInMiddle(int value,int position) {
  Node* new_node = new Node();
  new_node->data = value;
  Node* current = head;
  for (int i = 2; i < position; i++) {
    if (current != nullptr) {
      current = current->next;
    }
  }

  new_node->next = current->next;
  current->next = new_node;

}

void DeleteBegin(){
  if (head == nullptr) { // must check if the list is empty
    return;
  }
  head = head->next;
}

void DeleteEnd() { // we want to delete the pointer that points at null
  // ensure that the list has at least 2 nodes
  if (head == nullptr || head->next == nullptr) {
    return;
  }

  Node* current = head;
  while (current->next->next != nullptr) { // ensures that we're stopping 2 nodes away from the last node
    current = current->next;
  }
  current->next = nullptr;

  /*
    so if we have a list like 5->10->15->20-> nullptr, the loop will terminate when the current node is equal to 15 because when we
    get to node 15, current->next->next is nullptr since 20 follows 15 and nullptr follows 20. The loop terminates and we set 15 to 
    point at nullptr instead therefore deleting 20 from the list.
  */
}

void Deletemiddle(int position) {
  Node* current = head;
  for (int i= 2; i < position; i++) {
    if (current->next != nullptr) {
      current = current->next;
    }
  }
  current->next = current->next->next; // we make the node skip the node after it and point to the next one.
}

bool SearchList(Node* head, int key) {
  Node* current = head;
  while(current != nullptr) {
    if (current->data == key) {
      return true;
    }
    current = current->next;
  }
  return false;
}
