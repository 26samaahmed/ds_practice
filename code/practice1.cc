#include <iostream>
#include <memory>
/*

Exercise 1: Linked List Basics
Implement a simple singly linked list with the following functionalities:

Insert a node at the beginning of the list.
Insert a node at the end of the list.
Delete a node by value.
Display the elements of the linked list.

*/

// start by creating a node class that consists of a value and the pointer to the next node
// template since we don't have a specific data type
template <typename T>
class Node {
  public:
  // non default constructor
  Node(T value, std::shared_ptr<Node> pointer) : value_(value), next_(pointer) {}
  // setters and getters
  void SetValue(T value) {
    value_ = value;
  }

  void SetNext(std::shared_ptr<Node> next) {
    next_ = next;
  }

  T GetValue() {
    return value_;
  }

  std::shared_ptr<Node> GetNext() {
    return next_;
  }

  private:
  T value_;
  std::shared_ptr<Node> next_;
};

// create the class for the linked list that consists of the tail (last node in the list that points at the dummy node) 
// and the size of the list to keep track of how many nodes we have

template <typename T>
class LinkedList{
  public:
  // non default constructor
  LinkedList(size_t size, std::shared_ptr<LinkedList> tail) : size_(size), tail_(tail) {}
  // insert a node at the beginning of the list
  void PushFront(T value) {
    // start by create the dummy node where the tail points at it
    std::shared_ptr<Node<T>> dummy = tail -> GetNext(); // now tail points at dummy
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node>(value, dummy -> GetNext()) // now the node has the value and points at the node that dummy was pointing at
    // now let the dummy pointer point at the new node
    dummy -> SetNext(new_node);
    size_ ++;
  }

  // inserting at the end of the list
  void PushEnd(T value) {
    std::shared_ptr<Node<T>> dummy = tail -> GetNext(); // the tail now points at the dummy node
    std::shared_ptr<Node<T>> new_node = std::make_shared<Node>(value, tail -> GetNext()) 
    // since we want the new node to point at the node that the tail was pointing to aka the dummy node
    tail_ -> SetNext(new_node); // so that the tail now points at the new node
    tail_ = new_node; // then we change the tail to become the new node
    size_ ++; // don't forget to increment the size
  }

  private:
  size_t size_;
  std::shared_ptr<LinkedList> tail_;

};

// remember to practice recursion 
// learn linked lists using structs as well