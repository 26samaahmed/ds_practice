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
  return 0;
}