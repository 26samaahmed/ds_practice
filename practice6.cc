#include <iostream>
#include<stack>
// merging 2 sorted lists
// intersection of 2 linked lists
// checking if a linked list is a palindrome
// practice stacks and queues
// big o notation

// reversing a word using stack
void Reverse(std::string word) {
  std::cout << "original word is: " << word << "\n";

  // create an empty stack
  std::stack<char> stack;
  // now loop through the string so I can push each character into the stack
  for (char c: word) {
    stack.push(c);
  }

  // loop through the string again so i can start replacing characters
  for (int i = 0; i < word.size(); i++) {
    // store the character at the original position
    char original_char = word[i];
    // now replace the current char by the top element in the stack
    word[i] = stack.top();
    // now pop the top element so that we go through the string completely backwards. 
    //So if i have a word like hello, the top element would be o, so I will store h in a variable then replace h with o and then pop o from the stack,
    // so the word would look like this "oello" while the stack looks like this ['h', 'e', 'l', 'l'].
    stack.pop();
  }
  std::cout << "reverse word is: " << word << "\n";
}

struct Node {
  int data;
  Node* next;
};

// 2 pointers, one for the start of the list and one for the end of the list
Node* front;
Node* back;

// inserting in a queue
void InsertQueue(int value) {
  // check if the list is empty, if it is, then we set the back pointer to become the new node and then make front = back because there is only 1 node.
  if (front == nullptr) {
    back = new Node();
    back->data = value;
    back->next = nullptr;
    front = back;
  } else {
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    // traverse through the whole list until i reach the last node which points at nullptr so i can make it point at the new node instead
    Node* temp = front;
    for (temp->next != nullptr) {
      temp = temp->next;
    }
    // once the loop terminates, that means we reached the last node
    // make the last node point at the new node
    temp->next = new_node;
    // now the new node is that back
    back = new_node;
  }
  // if the list is is not empty, then pushing an element meaning adding it to the end as the new back where the original 
  // last node would point at the new node and the new last node would point at nullptr

}


// deleting in a queue

int main() {
  // test cases
  Reverse("hello");
  Reverse("nn");
  Reverse("c");
  Reverse("");
}