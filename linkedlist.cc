#include <iostream>
#include <memory>

// a class for each node that consists of an element and a pointer to the next node
template <typename T> 
class Node {
  public:

  void PushFront(T x) { //pushing an element into the front of linked list means that the new element becomes the first node/head
    // start by creating a dummy node that the tails points at
    std::shared_ptr<Node> dummy = tail_ -> GetNext();
    std::shared_ptr<Node> new_node = std::make_shared(x, dummy -> GetNext()); // now the new node points at the node that the dummy node was pointing at
    dummy.SetNext(new_node); // now we make the dummy node point at the new node
    // increment the size
    size- ++;
  }

  //pushing back to the end of the list so the new node becomes the tail
  void PushBack(T x) {
    // the tail points at the dummy node but now i want the tail to point at the new node and the new node to point at the dummy node
    std::shared_ptr<Node> new_node = std::make_shared(x, tail -> GetNext()); // now the new node points at the node that the tail was pointing at aka the dummy node
    tail -> SetNext(new_node); // let the tail point at the the new node
    tail_ = new_node; // update the value of the tail to become the new node now
    size_ ++; // increment the size
  }

  // removing an element from the front, must make sure the list is not empty so that we're not popping nothing

  void PopFront(T x) {
    if (size_ == 0) {
      throw std::out_of_range("this list is empty so we can't pop an element");
    }
    // start by creating the dummy node that the tail points to
    std::shared_ptr<Node> dummy = tail -> GetNext(),
    old_front = dummy -> GetNext(), // now we have the front node that we want to remove
    new_front = old_front -> GetNext(); // this is the 2nd node which will be the new front node that the dummy node points at
    dummy -> SetNext(new_front); //now i will make the dummy pointer point at the new node instead
    if (tail_ == old_front) { // if the list consists of only 1 node basically so we would be popping back and front
      tail_ = dummy; // if we remove the tail then there is nothing left in the list so it becomes empty
    }
  }


  // setters
  void SetElement(T element) {
    element_ = element;
  }

  void SetNext(std::shared_ptr<Node> next) {
    next_ = next;
  }

  // getters
  T GetElement() {
    return element_;
  }

  std::shared_ptr<Node> GetNext() {
    return next_;
  }

  private:
  std::shared_ptr<Node> next_;
  T element_; // did this since the value stored at the node could be of any data type which is why we used templates

};


// linked list class that consists of a bunch of nodes
template <typename T> // so that we can pass any data type instead of having repeated code for diff data types
class SLinkedList{
  public:
  int CountSize() {
    return CountSizeRec(tail->GetNext()->GetNext()) // tail->GetNext()->GetNext() is the head or the first node in the list so that we can start recursion from there
  }


  private:
  int CountSizeRec(std::shared_ptr<SLinkedList> ptr) {
    // if the ptr is the dummy node aka tail -> Next
    if (ptr == tail -> GetNext()) { // that is the base case that stops the recursion
      return 0;
    }
    int size_of_rest = CountSizeRec(ptr -> GetNext()); //recursion to keep checking until base case is reached
    return 1 + size_of_rest; // we increment the size as we go node by node
  }



  size_t size_;
  std::shared_ptr<SLinkedList> tail;

};
// will use shared pointers since multiple pointers can point at the same object

