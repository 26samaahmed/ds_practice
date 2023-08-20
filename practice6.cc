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


int main() {
  // test cases
  Reverse("hello");
  Reverse("nn");
  Reverse("c");
  Reverse("");
}