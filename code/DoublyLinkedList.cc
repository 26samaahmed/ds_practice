#include<iostream>
// doubly linked list
struct Node {
  int data;
  Node* next;
  Node* previous;
};

Node* head = nullptr;
// inserting a node at head
void InsertAtHead(int value) {
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = nullptr;
  new_node->previous = nullptr;
  if (head == nullptr) { // in case the list is empty
    head = new_node; // the head becomes the node we want to insert
    return;
  }
  head->previous = new_node; // since the node before the head is the new node
  new_node->next = head; // now the node points at the head
  head = new_node; // then the new_node becomes the head now since it's the first node in the list
}

void DisplayList() {
  Node* current_node = head; // so we start from the beginning of the list
  // in the loop, the condition should make sure that the current node's next value is not nullptr aka the last node in the list
  printf("list is: ");
  while (current_node != nullptr) {
    std::cout << current_node->data << " "; //print the data of the node
    current_node = current_node->next; // then we check the next node
  }
  printf("\n");
}


int main() {
  int input, x = 0;
  std::cout << "How many numbers in the list: ";
  std::cin >> input;
  for (int i = 0; i < input; i++) {
    printf("Enter the number \n");
    scanf("%d", &x);
    InsertAtHead(x);
    DisplayList();
  }
return 0;
}