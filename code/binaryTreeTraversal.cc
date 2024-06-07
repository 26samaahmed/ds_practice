#include <iostream>
using namespace std;

// Depth First Search
// Inorder Traversal of Binary Tree (left, root, right)
// Start by traversing the left subtree, then visit the root, and finally traverse the right subtree.

// a node has a left and right child, and a data value
struct Node {
  int data;
  Node* left;
  Node* right;
};

// Think of a robot visiting a node. Whenever the robot visits a node, it makes a note of where it is before moving to the lft child. once it finishes visiting
// the left child, it will come back to its note, print the current node's data, then moves to the right child
// Time complexity is O(n)
void printInorder(Node* node) {
  // Return to the parent node's function call
  if (node == nullptr) return;
  // start by using recursion to traverse the left subtree
  printInorder(node->left);
  cout << node->data << " ";

  // Traverse right subtree
  printInorder(node->right);
}

// Preorder Traversal of Binary Tree (root, left, right)
void printPreOrder(Node* node) {
  // Return to the parent node's function call
  if (node == nullptr) return;

  cout << node->data << " ";

  // start by using recursion to traverse the left subtree
  printInorder(node->left);

  // Traverse right subtree
  printInorder(node->right);
}

// Postorder Traversal of Binary Tree (left, right, root)
void printPostOrder(Node* node) {
  // Return to the parent node's function call
  if (node == nullptr) return;

  // start by using recursion to traverse the left subtree
  printInorder(node->left);

  // Traverse right subtree
  printInorder(node->right);

  cout << node->data << " ";
}