#include <iostream>
// linked lists
struct Node {
  int data; // to hold the data
  Node* next_value; // a pointer to the next node
};

// we could start by initializing the head node to be null so that we can change the value later when we add a node
Node* head = nullptr;

void InsertBegin(int value) { // this is how i think it would be implemented [inserting at the beginning of the list]
// we are already given the value that needs to be stored in the new node
// start by creating the new node
Node* new_node = new Node(); // allocates memory in the heap
new_node->data = value; // we store the value inside the new node
// then we make the new node point at the head
new_node->next_value = head;
// and then we make the new head become the new node
head = new_node;
}

// printing the list
void DisplayList() {
  Node* current_node = head; // so we start from the beginning of the list
  // in the loop, the condition should make sure that the current node's next value is not nullptr aka the last node in the list
  printf("list is: ");
  while (current_node != nullptr) {
    std::cout << current_node->data << " "; //print the data of the node
    current_node = current_node->next_value; // then we check the next node
  }
  printf("\n");
}

//inserting a node at the end
void InsertEnd(int val) {
  // start by creating a new node
  Node* new_node = new Node(); // allocating in the heap
  // we want the new node to be the one pointing at null and making the new node become the tail of the list aka last node
  new_node->data = val; // so now the new node holds the value we want
  // now we make the new node point at null
  new_node->next_value = nullptr;

  // if the list is empty then we make the head equal to the new node
  if (head == nullptr) {
    head = new_node;
    return;
  }

  Node* current_node = head;
  while (current_node != nullptr) {
    current_node = current_node->next_value;
  }
  // this executes when we traversed through the whole list and now are the last node so we make the last node point at the new node
  current_node->next_value = new_node;
}

// inserting at a specifc position
void InsertAtGivenPosition(int val, int position) {
  // start by creating a node that holds the new value
  Node* new_node = new Node();
  new_node->data = val;

  // if we want to insert at position 1, then we need to make the new node point at the head and make the new node become the head of the list
  if (position == 1) {
    new_node->next_value = head;
    head = new_node;
    return;
  }
  Node* current = head; // to start from the first node
  // the position - number is basically where i want to insert the node. So if I want to insert a node at poosition 4, then i would do position - 4
  for (int i = 0; i < position - 3; i++) {
    current = current->next_value;
  }
  // make the new node point at whatever the old node at the position we want to insert was pointing at
  new_node->next_value = current->next_value;
  // then make the old node point at the new node
  current->next_value = new_node;
}

int main() {
  int input, x = 0;
  std::cout << "How many numbers in the list: ";
  std::cin >> input;
  for (int i = 0; i < input; i++) {
    printf("Enter the number \n");
    scanf("%d", &x);
    InsertBegin(x);
    DisplayList();
    InsertAtGivenPosition(4, 2);
  }
return 0;
}

// inserting first/end node (done)
// deleting first/last node
// inserting before or after a specific given node (done)
// deleting a specific node
// displaying/traversing a list (done)
// searching for a node with a specific value
// retrieving the value of the specifc node
// find the position of a specific value
// merging two linked lists
// reversing a list