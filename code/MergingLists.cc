#include <iostream> // in progess/ having issues
// merging 2 lists. I would want to create 2 lists and start by comparing the value of the first node in each. Whichever has
// a smaller value will get pushed first into the new list and we will move it's counter to the next node and compare it with
// the value in the node from the other list that was not pushed.
struct Node {
  int data;
  Node* next;
};

// now create a function that accepts 2 heads where we get to compare values from both lists
Node* MergeLists(Node* List1, Node* List2) {
  // create an empty list where we would keep pushing values from both lists to combine them
  Node* List3 = new Node();
  Node* temp = List3;

  // now we will loop through the both lists. As long as both lists are not empty then the loop will keep iterating
  while (List1 != nullptr && List2 != nullptr) {
    if (List1->data < List2->data) { // if list 1's node is less than list 2's node
      temp->next = List1; // we make the current node point at the node that was from List 1
      // and then we move to the next node now that we're done with the node that's pushed
      List1 = List1->next;
    } else if (List2->data < List1->data) {
      temp->next = List2; // we make the current node point at the node from list 2
      // then we move on to the following node from list 2 until it's empty
      List2 = List2->next;
    }

    temp = temp->next;
  }

  // append any remaining nodes if there's any
  if (List1 == nullptr) {
    temp->next = List2;
  }
  if (List2 == nullptr) {
    temp->next = List1;
  }

  return List3->next;
}

void Display(Node* head) {
  Node* temp = head;
  while (temp != nullptr) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << "\n";
}

int main() {
  // create the first list
  Node* n3 = new Node();
  n3->data = 1;
  n3->next = nullptr;
  Node* n2 = new Node();
  n2->data = 7;
  n2->next = n3;
  Node* n1 = new Node();
  n1->data = 9;
  n1->next = n2;
  Node* List1 = n1;

  // create second list
  Node* n6 = new Node();
  n6->data = 2;
  n6->next = nullptr;
  Node* n5 = new Node();
  n5->data = 4;
  n5->next = n6;
  Node* n4 = new Node();
  n4->data = 8;
  n4->next = n5;
  Node* List2 = n4;

  Node* List3 = MergeLists(List1, List2);
  Display(List3);
}