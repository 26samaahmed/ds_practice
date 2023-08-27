#include<iostream>

struct Node {
  int data;
  Node* next;
};

Node* head = nullptr;

// reversing a linked list (done)
void Reverse() {
  Node* next_node = nullptr;
  Node* previous = nullptr;
  Node* current = head;
  while (current != nullptr) {
    next_node = current->next; // so if we have a list 1->2->3 and we're starting from the head which is points at node 1, then we're storing the value 2 before we change where 1 points at
    // now make each node point at the node before it
    current->next = previous;
    // now we're going to change the value of previous to become the current we're on so the next node points at it
    previous = current;
    // now move on to the next node
    current = next_node;

  }
}

struct Node2 {
  int data;
  Node2* next;
  Node2* previous;
};

Node2* head2 = nullptr;

// just for testing my deletion function
void InsertBegin(int value) {
  // start by creating a new pointer and we're going to allocate in the heap
  Node2* new_node = new Node2();
  new_node->data = value;
  new_node->next = nullptr;
  // now check if the list is empty, because if it is, the we make the new node just point at nullptr
  if (head2 == nullptr) {
    head2 = new_node;
  } else { // if the list is not empty
    head2->previous = new_node; // because i want the first node to point at the new_node before it
    // now i will make the new node point at it's next node which is head
    new_node->next = head2; 
    // now i'm going to update the head to point at the new node
    head2 = new_node;
  }

}

void display() {
  Node2* temp = head2;
  while (temp != nullptr) {
    std::cout << "node is: " << temp->data << "\n";
    temp = temp->next;
  }
}

// doubly list delete at beginning (done)
void DeleteBegin() {
  // i will start by creating a copy of the original node that head points to in order to delete later before i change where the head points to
  // check if the list is empty
  if (head2 == nullptr) {
    std::cout << "nothing is in the list therefore nothing can be deleted\n";
    return;
  }
  // check if there is only 1 node
  if (head2->next == nullptr) {
    delete head2;
    return;
  }
  Node2* temp = head2;
  head2 = temp->next;
  delete temp;
}

// doubly list delete at specifc position (done)
void DeleteAtPosition(int position) {
  // traversing through the list
  Node2* temp = head2;
  // check if the the list is empty so an underflow doesn't happen
  if (head2 == nullptr) {
    std::cout << "nothing is in the list therefore nothing can be deleted\n";
    return;
  }

  // check if the there is only 1 node
  if (position == 1) {
    head2 = temp->next; 
    delete temp; // deleting the original head
    return;
  }

  // traverse through the list until I reach right before the position where the node needs to be deleted
  for (int i = 2; i < position; i++) {
    temp = temp->next;
  }

  // once the loop terminates, this means I've reached where the node needs to be deleted
  temp->next = temp->next->next; // i'm making the current node skip the node right after it and point at the node that was after the node that was skipped
  // since it is a doubly linked list, make sure that the node after the one we skipped also points back at the current node
  temp->next->previous = temp->next; // i'm updated the previous pointer of the node after the one i deleted to point back at the node before the dleted node
}


// doubly list delete at end (done)
void DeleteEnd() {
  Node2* temp = head2;

  if (head2 == nullptr) {
    std::cout << "nothing is in the list therefore nothing can be deleted\n";
    return;
  }

// check if the there is only 1 node
  if (head2->next == nullptr) {
    delete head2;
    return;
  }

  // i want to stop traversing through the list once i reach a node that points to a node that points at nullptr
  // so if my list is 1->2->3-> Null, I want to stop once i reach 2 because 2 points at 3 and 3 points at nullptr. I want to make 2 point at nullptr
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }
  temp->previous->next = nullptr; // updating the second to last node to point at nullptr
}

int main() {
  InsertBegin(4);
  InsertBegin(3);
  InsertBegin(2);
  InsertBegin(1);
  // so the list looks like this 1->2->3->4
  DeleteBegin(); // this should delete 1
  DeleteEnd(); // should delete 4
  DeleteAtPosition(1); // this would delete 2
  display();
  
}