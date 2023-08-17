// queues
#include <iostream>
#include <queue>

struct Node {
  int data;
  Node* next;
};

Node* front = nullptr;
Node* back = nullptr;


// inserting an element in a queue using linked lists
void Insert(int value) {
  // we start by checking if the list is empty. Since we are inserting from the back side, check if back is equal to nullptr
  if (back == nullptr) {
    back = new Node(); // allocate the pointer in the heap
    back->data = value;
    back->next = nullptr; // since there is only 1 node, then it should point at nullptr
    front = back; // having only 1 node means the front and back are equal
  } else { // if the list is not empty
    // create a new node, allocate in the heap, assign it's value to the one given when the function is called
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    // now traverse through the whole list so i can reach the last node where the new node should be inserted
    Node* temp = front;
    // we want to reach a node that points to nullptr so we can change where it points to (should point to the new node and the new node should point to nullptr)
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    // now make the last node we reached point at the new node instead of pointing at nullptr
    temp->next = new_node;
    new_node->next = nullptr;
    back = new_node; // now the last element is the new node
  }
}

void Delete() { // happens from the front end of the list (the first element i pushed is first element that would be popped)
// keep in mind: must check if the the list is empty, because if it is, then I'd be deleting something that doesn't exist therefore causing an underflow in my program
// If the list is not empty, then i would want to delete the front element and assign it to nullptr, then make the next first node become the new front
// check if there is only 1 node, because if there is, then that means front and back are equal, so delete the front and assign both to nullptr
  if (front == nullptr) {
    std::cout << "nothing can be popped because there are no node. This will cause an underflow\n";
    return;
  } else if (front == back) { // if there is only 1 node
    delete front;
    front = nullptr;
    back = nullptr;
  } else { // if the list is neither empty nor has only 1 node, then i must delete the first node in the list
    // create a pointer to keep the orignal front node so we can delete it later
    Node* temp = front;
    // now make the front become the second node since we're deleting the first node
    front = front->next;
    // delete the copy of the original front node
    delete temp;
  }

}

void Display() {
  Node* temp = front;
  while (temp != nullptr) {
    std::cout << "node value is: " << temp->data << "\n";
    temp = temp->next;
  }
}

int main() {
    // all test cases for insertion pass :)
    // Test Case 1: Inserting into an Empty Queue
    Insert(5);
    Insert(10);
    Insert(15);
    Delete();
    Display();
    std::cout << "--------\n";

    // Test Case 2: Inserting into a Non-Empty Queue
    Insert(5);
    Insert(10);
    Insert(15);
    Insert(20);
    Delete();
    Display();
    std::cout << "--------\n";

    // Test Case 3: Inserting a Single Element Multiple Times
    Insert(5);
    Insert(5);
    Insert(5);
    Delete();
    Display();
    std::cout << "--------\n";

    // Test Case 4: Inserting Alternating Elements
    Insert(5);
    Insert(10);
    Insert(15);
    Insert(20);
    Delete();
    Display();
    std::cout << "--------\n";

    // Test Case 5: Inserting Mixed Elements
    Insert(5);
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(10);
    Insert(15);
    Delete();
    Display();
    std::cout << "--------\n";

    // Test Case 6: Inserting Large Number of Elements
    for (int i = 1; i <= 100; i++) {
        Insert(i);
    }
    Display();
}