#include <iostream>
// singly linked lists
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

// deleting a node at a specific position
void DeleteElement(int position) { // revise this
  Node* current = head;
  if (position == 1) {
    head = current->next_value;
    delete current;
    return;
  }
  for (int i = 0; i < position - 1; i++) { 
    current = current->next_value;
  }
  // this points to the node we want to delete
  Node* node = current->next_value; // nth node
  // now instead of current poitning at the node right after it, it skips it and points at the one after
  current->next_value = node->next_value; // (n+1)th node
  delete node; // then we delete the node that needs to be skipped.
}

// reverse a linked list
void ReverseList(){
  Node* current = head; // this is used so that we can traverse the list from the first node aka the head.
  Node* previous = nullptr; // this is so that the every node points at the previous node instead of the following node
  Node* next;
  while (current != nullptr) { // as long as the node isn't pointing at nullptr aka the tail of the list
    next = current->next_value; // saving the pointer of the next node so that we don't lose the link
    current->next_value = previous; // here, we make the current node point at the node before it instead of the one after it
    previous = current; // update the previous node to becone the current node, this is used to keep the track of the node before the current node
    current = next; // now we're moving on to the next node
  }
  head = previous; // this sets the head to the last node in the list
}

/*
so if we have a list that goes like this 1 -> 2 -> 3 -> nullptr and we want to reverse it, this is how it would get started.
 We would check if 1 is not equal to nullptr which it is true so we go through the body of the while loop. Now we store the value 
 2 in a node called next so that we don't lose the link and then we make the current node aka 1 point at the node before it which 
 is nullptr. Now when we say current = previous, we are storing the node with value 1 in the variable previous so that when we go
 through the while loop again, node 2 which is the current node should point at previous which is node 1. When we say current = next,
 we're moving to the next node which is node 2 so that we can loop again. Now if we go through the loop again, node 2 which the 
 current node is not equal to nullptr, so we implement the body of the while loop. We store the node that 2 is pointing at so 
 that we don't lose the link between them. So now next is equal to 3. and then we're making 2 point at 1 instead of 3. Then,
 we say that previous = 2 so that when we go through the loop again, 3 would point at previous aka 2. When we say current = next,
 current becomes node 3 and then we repeat the same process again.
*/

// printing a list using recursion
void Print(Node* node) {
  if (node == nullptr) { // if the node is null
    return; // just exit the program
  }
  printf("%d", node->data); //printing the value of the current node
  Print(node->next_value); // recursive call to move on to the next node
}

// reversing a list through recursion
void RecursionReverse(Node* node) {
  if (node == nullptr) { // base case to break the recursion. Once we reach the end of the list, that means that node = nullptr
    head = node; // and we make the last node become the head
    return; // exit
  }
  RecursionReverse(node->next_value); // recursive call until we reach the base case
  Node* q = node->next_value; // we are storing the node following the current node
  q->next_value = node; // now the current node will point at the node before it instead of the following it.
  node->next_value = nullptr; // now we make the first node point at nulltr
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
    ReverseList();
  }
return 0;
}

// inserting first/end node (done)
// inserting before or after a specific given node (done)
// displaying/traversing a list (done)
// reversing a list (done)
// deleting first/last node
// deleting a specific node
// searching for a node with a specific value
// retrieving the value of the specifc node
// find the position of a specific value