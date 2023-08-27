#include <iostream>

struct Node {
  int data;
  Node* next;
};

Node* head = nullptr;

void Insert(int value) {
  // first check if the list is empty because if it is, then make the head pointer point to the new node
  // if the list is not empty then we create a new node, set it's next pointer to the current first node then make the head ptr point at the new node to make it the first node
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = nullptr;
  if (head == nullptr) {
    head = new_node;
    return;
  } else {
    new_node->next = head; // we're making the new node point at the first node
    head = new_node; // now the head pointer should point at the new node
  }
}

// insert at given position
void InsertPosition(int value, int position) {
  // check if the list is empty or if the position is 1
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = nullptr;
  if (head == nullptr) {
    head = new_node;
    return;
  } else if (position == 1) {
    new_node->next = head;
    head = new_node;
    return;
  } else {
    Node* temp = head;
    for (int i = 2; i < position; i++ ) {
      temp = temp->next;
    }
    new_node->next = temp->next; // now make the new node point at what the current node is pointing at. If i have a list 1->2->4 and i want to insert 3 after 2, then I want to make 3 point at 4
    temp->next = new_node;// now we're making 2 point at 3
  }
  
}

void Display() {
  Node* temp = head;
  while (temp != nullptr) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << "\n";
}

//insert at end
void InsertEnd(int value) {
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = nullptr;
  if (head == nullptr) {
    head = new_node;
    return;
  } else {
    // traverse through the list until we reach the node that points at nullptr
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    // now that i reached the last node, make it point at the new node
    temp->next = new_node;
    // new node already points at nullptr by default that i had above when i set its value and next pointer
  }

}

// reversing a linked list
void Reverse() {
  Node* previous = nullptr; // so we can make each node point at the one before it
  Node* temp = head;  // to traverse through the list
  Node* next_node = nullptr;// to store the next node before we change where the current node points so that i don't lose the link
  while (temp != nullptr) {
    // first, store the current node's next node somewhere so we can access it later
    next_node = temp->next; // so if i have a list 1->2->3 then i'm storing 2 before i change where 1 points to
    temp->next = previous; // now i'm making the current node point at the one before it. So now 1 points at nullptr
    // now we want node 1 to become the previous node so that in the next iteration 2 can point at it
    previous = temp;
    // now we move on to the next node to continue traversing
    temp = next_node;
  }
  head = previous; // the last node we reached now becomes our first node, in the example above, the head now points at 3
} 

int main() {
  Insert(4);
  Insert(3);
  Insert(2);
  Insert(1);
  InsertPosition(100, 2);
  InsertEnd(9);
  Display();
  Reverse();
  Display();
}