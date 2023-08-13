#include<iostream>
#include<stack>

struct Node {
  int data;
  Node* next;
};

Node* top = nullptr;
void Push(int value) { 
  Node* new_node = new Node();
  new_node->data = value;
  new_node->next = top;
  top = new_node;
}

void Pop() {
  if (top == nullptr) { // if the list is empty
    return;
  }
  Node* copy = top;
  top = top->next; // changing the value of top to become the node after it
  delete copy;
}

// reversing word using stack
void ReverseWord(std::string word) {
  std::stack<char> stack2;
  // pushing each character from the string into the stack
  for (int i = 0; i < word.size(); i++) {
    stack2.push(word[i]);
  }
  std::cout << "top element is: " << stack2.top() << "\n"; // this prints out a which is the last element i pushed

  for (int i = 0; i < word.size(); i++) {
    word[i] = stack2.top();
    stack2.pop();
  }
  std::cout << "Reversed word is: " << word << "\n";
}


void Reverse(std::string word) {
  int j = word.size() - 1; // so i can access the last letter
  for (int i = 0; i < j; i++) { // we do i < j so that we stop once we reach the middle character
    char copy = word[i]; // keeping a copy of it before it gets overwritten
    word[i] = word[j]; // we set whatever is at index i to the value that is at index j
    // ex: if we have "wowa", this becomes "aowa" because we set index 0 which is the first letter to the value at index j which was a
    word[j] = copy; // and now the word becomes "aoww" since we're setting the character at index j which is a and changing its value to the value at i which is w
    j--; // since we are at the last index and want to get the characters before it.
  }
  std::cout << "reversed word is (without stack): " << word << std::endl;
}

int main() {
  std::stack<int> stack;
  stack.push(1);
  std::cout << "size is " << stack.size() << "\n";
  stack.push(2);
  std::cout << "size is " << stack.size() << "\n";
  stack.push(3);
  std::cout << "size is " << stack.size() << "\n";
  if (!stack.empty()) { // must make sure that the stack is not empty before i print the top element
  std::cout << "top element is " << stack.top() << "\n"; // should print the most recent element i added aka 3
  }
  std::cout << "----\n";
  ReverseWord("aloha");
  Reverse("hello");
}