#include <iostream>

// reversing a linked list
// merging 2 sorted lists
// intersection of 2 linked lists
// checking if a linked list is a palindrome
// doubly list delete at beginning
// doubly list delete at specifc position
// doubly list delete at end

struct Node {
  int data;
  Node* next;
  Node* prior;
};

Node* head = nullptr;
// 2 pointers i want to create. A pointer that points at the next node as well as a pointer that points at the prior node

// double list insert at beginning (done)
void InsertBegin(int value) {
  // start by creating a new pointer and we're going to allocate in the heap
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = nullptr;
  // now check if the list is empty, because if it is, the we make the new node just point at nullptr
  if (head == nullptr) {
    head = new_node;
  } else { // if the list is not empty
    head->prior = new_node; // because i want the first node to point at the new_node before it
    // now i will make the new node point at it's next node which is head
    new_node->next = head; 
    // now i'm going to update the head to point at the new node
    head = new_node;
  }

}

// doubly list insert at specifc position (done)
void InsertPosition(int value, int position) { // NOTE: experiment and see whether i = 2 or i =1 works and how they differ.
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = nullptr;
  new_node->prior = nullptr;
  // take into account if the list is empty or the if position is 1.
  if (head == NULL) {
    head = new_node;
    return;
  } else if (position == 1) { // if the position is 1, then we make the new node point at the head
    new_node->next = head;
    head->prior = new_node;
    head = new_node;
    return;
  } else {
    // create a copy of the head node so that i can traverse through the list
    Node* temp = head;
    for (int i = 2; i < position; i++) {
    temp = temp->next;
    }
    // once i exit the loop, the i just reached the node right before the position i want to insert
    // i will make the node i stopped at point to the new node and the make the new node's prior pointer point at the node before it
    new_node->next = temp->next; // the new node's points at whatever the node at that position was pointing
    new_node->prior = temp; // then the new node's prior pointer points at the node before it
    temp->next = new_node; // then the node at that pos
    temp->next->prior = new_node;
  }
}

/*
Note: for the for loop in the function, I was confused on whether to use i = 1 or i = 2.
After testing multiple test cases, this is what happens. Let's say my list looks like this 15 -> 5 -> 10
and i wanted to insert a node with value 1000 in position 3. When I tried inserting 1000 using i = 1 for the for loop condition,
it would replace whatever is at position 3 with the value I want to insert. So the list would look like this 15 -> 5 -> 1000 so 
1000 replaced 100. However, when I use i = 2, 100 gets moved to position 4 when I want to insert 1000 in position 3 so the original value
at the position is pushed to the front rather than get replaced which is what should happen. The list then looks like this:
15 -> 5 -> 1000 -> 10. 
*/


// doubly list insert at end (done)
void InsertEnd(int value) {
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = nullptr;
  new_node->prior = nullptr;
  // to check if the list is empty. If it is, set the head to point at the new node
  if (head == nullptr) {
    head = new_node;
  } else { // if the list is not empty
    // traverse through the list and stop at the node that points at nullptr
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    // make the last node's next pointer point at the new node
    temp->next = new_node;
    // now make the new node's prior pointer point at the node before it to make it doubly linked
    new_node->prior = temp;
    // now make the new node point at nullptr now that it is the last node
    new_node->next = nullptr;
  }
}


// reverse singly linked list (need to repracrice this one again)
void Reverse() {
  /* creeating 3 pointers. 
  1. A current pointer that starts from the head so I can keep traversing through the list.
  2. A previous pointer so we can switch the link between each node. Meaning that each node would point to the node prior to it rather than the one after it.
  3. A next pointer to store the value of the next node so we don't lose the link when we make each node point at the previous node
  */
 Node* current = head;
 Node* next = nullptr;
 Node* previous = nullptr;
 // traverse through the list meaning that the while loop should execute as long as i haven't reached nullptr.
 while (current != nullptr) {
  // now store the value of the current node's next node so that when I change where the current node points at, I don't completely lose the link
  next = current->next;
  // now, i'm going to make the current node point at the node before it
  current->next = previous;
  // now, we're going to update the value of the previous node to become the current node so we can keep traversing through the list.
  previous = current;
  // now update the value of current to become the next node in the list
  current = next;
 }

  head = previous;
}


void display() {
  Node* temp = head;
  while (temp != nullptr) {
    std::cout << "node is: " << temp->data << "\n";
    temp = temp->next;
  }
}

int main() {
  // test case to test my functions :)
  InsertBegin(10); // List: 10
  InsertPosition(0, 1);
  display();
  std::cout << "-----\n";

  // Insert nodes at the beginning
  InsertBegin(5);  // List: 5 -> 10
  InsertBegin(15); // List: 15 -> 5 -> 10
  InsertPosition(1000, 3);
  InsertEnd(50);
  display();
  std::cout << "-----\n";

  // Insert more nodes
  InsertBegin(20); // List: 20 -> 15 -> 5 -> 10
  InsertBegin(25); // List: 25 -> 20 -> 15 -> 5 -> 10
  display();
  std::cout << "-----\n";

  // Insert a node into an empty list
  head = nullptr;
  InsertBegin(100); // List: 100
  display();
  std::cout << "-----\n";

  // Insert a single node multiple times
  for (int i = 0; i < 5; i++) {
      InsertBegin(50); // List: 50 -> 100
  }
  display();
  std::cout << "-----\n";

  // Insert nodes after deleting some
  InsertBegin(30);  // List: 30 -> 50 -> 100
  InsertBegin(40);  // List: 40 -> 30 -> 50 -> 100
  Reverse();
  display();
}