#include "AVL.h"
#include <iostream>

// ----------------------------------------------------------------------------
// public ---------------------------------------------------------------------
// ----------------------------------------------------------------------------

AVL::AVL() {
  root = NULL;
}

AVL::~AVL() {
  clear();
}

NodeInterface* AVL::getRootNode() {
  return root;
}

bool AVL::add(int data) {
  if (recursiveFind(root, data)) {
    // cout << data << " not added, already exists." << endl;
    return false;
  }
  root = recursiveAdd(root, data);
  // cout << data << " added successfully." << endl;
  return true;
}

bool AVL::remove(int data) {
  if (root == NULL) {
    // cout << data << " tree is empty, remove failed." << endl;
    return false;
  } else if (!recursiveFind(root, data)) {
    // cout << data << " not in tree, remove failed."<< endl;
    return false;
  } else {
    root = recursiveRemove(root, data);
    if (!recursiveFind(root, data)) {
      // cout << data << " removed successfully." << endl;
      return true;
    } else {
      // cout << data << " not removed successfully." << endl;
      return false;
    }
  }
}

void AVL::find(int data) {
  if (recursiveFind(root, data)) {
    // cout << data << " found in tree." << endl;
  } else {
    // cout << data << " not found in tree." << endl;
  }
}

void AVL::preOrderPrint() {
  recursivePreOrderPrint(root);
}

// ----------------------------------------------------------------------------
// private --------------------------------------------------------------------
// ----------------------------------------------------------------------------

Node* AVL::recursiveAdd(Node* parent, int data) {
  if (parent == NULL) {
    parent = new Node(data);
  } else if (data < parent->data) {
    parent->left_child = recursiveAdd(parent->left_child, data);
  } else {
    parent->right_child = recursiveAdd(parent->right_child, data);
  }
  return balance(parent);
}

Node* AVL::recursiveRemove(Node* parent, int data) {
  if (data < parent->data) {
    parent->left_child = recursiveRemove(parent->left_child, data);
  } else if (data > parent->data) {
    parent->right_child = recursiveRemove(parent->right_child, data);
  } else {
    if (parent->left_child != NULL) {
      // case 1: has left child
      parent->left_child = replaceIOP(parent->left_child, parent);
    } else {
      // case 2: no left child
      Node* temp = parent;
      parent = parent->right_child;
      delete temp;
    }
  }
  return balance(parent);
}

Node* AVL::balance(Node* node) {
  if (node == NULL) {
    return node;
  }
  setHeight(node);
  // right imbalance
  if (getBalance(node) == -2) {
    // if right left imbalance, rotate the right child
    if (getBalance(node->right_child) > 0) {
      node->right_child = rotateRight(node->right_child);
    }
    return rotateLeft(node);
  }
  // left imbalance
  if (getBalance(node) == 2) {
    // if left right imbalance, rotate the left child
    if (getBalance(node->left_child) < 0) {
      node->left_child = rotateLeft(node->left_child);
    }
    return rotateRight(node);
  }
  return node;
}

Node* AVL::rotateRight(Node* node) {
  // rotate
  Node* child = node->left_child;
  node->left_child = child->right_child;
  child->right_child = node;
  // update heights
  setHeight(node);
  setHeight(child);
  return child;
}

Node* AVL::rotateLeft(Node* node) {
  // rotate
  Node* child = node->right_child;
  node->right_child = child->left_child;
  child->left_child = node;
  // update heights
  setHeight(node);
  setHeight(child);
  return child;
}

Node* AVL::replaceIOP(Node* current, Node* parent) {
  if (current->right_child != NULL) {
    current->right_child = replaceIOP(current->right_child, parent);
    return current;
  }
  Node* temp = current->left_child;
  parent->data = current->data;
  delete current;
  return balance(temp);
}

int AVL::getBalance(Node* node) {
  return getHeight(node->left_child) - getHeight(node->right_child);
}

int AVL::getHeight(Node* node) {
  if (node == NULL) {
    return -1;
  } else {
    return node->height;
  }
}

int AVL::getMax(int first, int second) {
  return (first > second) ? first : second;
}

bool AVL::recursiveFind(Node* parent, int data) {
  if (parent == NULL) {
    return false;
  } else if (data == parent->data) {
    return true;
  } else if (data < parent->data) {
    return recursiveFind(parent->left_child, data);
  } else {
    return recursiveFind(parent->right_child, data);
  }
}

void AVL::setHeight(Node* node) {
  node->height = getMax(getHeight(node->left_child),
      getHeight(node->right_child)) + 1;
}

void AVL::recursivePreOrderPrint(Node* root) {
  if (root != NULL) {
    cout << "Node: " << root->data << ", height: "
      << (root->height) << "\n";
    recursivePreOrderPrint(root->left_child);
    recursivePreOrderPrint(root->right_child);
  }
}

void AVL::clear() {
  while (root != NULL) {
    root = recursiveRemove(root, root->data);
  }
}
