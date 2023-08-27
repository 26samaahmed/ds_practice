#include<iostream>
#include<stack>
// practicing stack + linked lists
// checking for balanced parantheses
/*
the possible types of opening parantheses we have are: {, (, [
if found in the string, then we push into the stack, and then if we find a closing parantheses that matches then we pop it from 
the stack. If the stack is empty by the end of the operation, then it is balanced otherwise it's not since we have opening parantheses 
with no closing parantheses or vice versa.
*/

void CheckBalance(std::string parantheses) {
  // create a stack to that i can push opening parantheses in it.
  std::stack<char> stack;
  // since i will be given a string, i would want to loop through each character first so that i can push an opening parantheses
  for (char c: parantheses) {
    // we check if c is an opening parantheses
    if (c == '[' || c == '{' || c == '(') {
      //std::cout << "pushing this: " << c << "\n";
      stack.push(c);
      // if we have opening parantheses, i want to check if they have matching closing parantheses
    } else if (c == ']' || c == '}' || c == ')') {
      if (stack.empty()) { // if the stack is empty, then that means no opening bracket was pushed therefore it's unbalanced
        std::cout << "false\n";
        return;
      }
      else { // if the stack is not empty, then we start by checking whether the top brace matches the closing brace
        char top = stack.top();
        if ((c == ']' && top == '[')
        || (c == '}' && top == '{')
        || (c == ')' && top == '(')) {
          stack.pop();
        }
      }
    }
  }

  if (stack.size() == 0) { // after looping, ill check if the stack size is 0 because if it then it's balanced otherwise it's not.
    std::cout << "true\n";
    std::cout << "-------------\n";
  } else {
  std::cout << "false\n"; // if there aren't any of these opening braces then there are closing parantheses with no opening ones so it is automatically unbalanced.
  std::cout << "-------------\n";
  }
}

struct Node {
  int data;
  Node* next;
};
Node* head = nullptr;

void InsertBegin(int value) {
  Node* new_node = new Node(); // creating a pointer and allocating in the heap
  new_node->data = value; // assign the value we're passing into the function argument when we call it
  if (head == nullptr) { // if the list is empty
    head = new_node; // the new_node becomes the head (first node in the list)
    return;
  } else{  // if the list is not empty
    // we make the new node point at the head
    new_node->next = head;
    head = new_node; // now the new node becomes the head since it's the first node in the list
  }
}

void InsertPos(int value, int position) {
  Node* new_node = new Node();
  new_node->data = value;
  // i have to traverse through the list
  Node* temp = head;
  // check if the list is empty because we wouldn't be able to insert in the middle
  if (head == nullptr || position == 1) {
    new_node->next = head;
    head = new_node;
    return;
  }

  for (int i = 2; i < position; i++) {
    temp = temp->next;
  }
  new_node->next = temp->next; // so if we have 1 -> 2 -> 4 and we want to insert 3 between 2 and 4, then we want 3 to point at whatever 2 is pointing at
  temp->next = new_node;
}

void InsertEnd(int value) {
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = nullptr;
  Node* temp = head;
  if (head == nullptr) { // if the list has no nodes yet
    head = new_node;
  }
  // traverse through the whole list
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = new_node; // then we make the last node point to our new_node
}


void DisplayList() {
  Node* temp = head;
  while (temp != nullptr) {
    std::cout << "node is " << temp->data << "\n";
    temp = temp->next;
  }
}

void DeleteBegin() {
  Node* temp = head;
  head = temp->next;
  delete temp;
}

void DeleteEnd() {
  Node* temp = head;
  /*
  let's say i have a list like this 1->2->3->nullptr and I want it to become 1->2->nullptr, I would want to traverse
  through the list until i reach right before a node whose next pointer is nullptr. In this case, I want to stop once i reach
  the node with value 2 because once i exit out of the loop, I want to make 2 point at nullptr instead of 3.
  */
  while (temp->next->next != nullptr) {
    temp = temp->next;
  }
  temp->next = nullptr; //following with the example above, this makes 2 points at nullptr
  delete temp;
}

void DeletePos(int position) {
  // in order for me to delete anode from the middle, the node must have at least 2 nodes
  if (head->next == nullptr || position == 1) {
    std::cout << "list must have at least 2 nodes in order to pop something\n";
    return;
  }
  Node* temp = head;
  for (int i = 2; i < position; i++) {
    temp = temp->next;
  }
  temp->next = temp->next->next;
  delete temp;
}

// inserting at begin (done)
// inserting at specific position (done)
// inserting at end (done)
// deleting at begin (done)
// deleting at specific position (done)
// deleting at end (done)


int main() {
  CheckBalance("([]{()})"); // expected output: true (passed)
  CheckBalance("(([{)}"); // expected output: false (passed)
  CheckBalance("[{()}]"); // expected output: true (passed)
  CheckBalance("{[()]}"); // expected output: true (passed)
  CheckBalance("{[()}"); // expected output: false (passed)
  CheckBalance("(((((((("); // expected output: false (passed)
  CheckBalance(""); // expected output: true (passed)
  CheckBalance("({[)]}"); // expected output: false (passed)
  CheckBalance("{[({})]}"); // expected output: true (passed)
  CheckBalance("abcdef"); // expected output: true (passed)
  CheckBalance("a(b)c[d]e{f}"); // expected output: true (passed)
  InsertBegin(5);
  InsertBegin(4);
  InsertBegin(3);
  InsertPos(9, 1);
  InsertEnd(100);
  DisplayList();
  std::cout << "-------\n";
  DeleteBegin();
  DisplayList();
  std::cout << "-------\n";
  DeleteEnd();
  DisplayList();
  std::cout << "-------\n";
  DeletePos(3);
  DisplayList();

  return 0;
}