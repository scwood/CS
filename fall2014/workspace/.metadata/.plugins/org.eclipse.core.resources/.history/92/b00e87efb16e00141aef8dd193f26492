#include "BST.h"

BST::BST() {
	root = NULL;
}

BST::~BST() {
}

NodeInterface* BST::getRootNode() {
	return root;
}

bool BST::add(int data) {
	if (find(root, data)) {
		std::cout << data << " not added, already exists." << endl;
		return false;
	}
	root = recursiveAdd(root, data);
	std::cout << data << " added successfully." << endl;
	return true;
}

Node* BST::recursiveAdd(Node* parent, int data) {
	if (parent == NULL) {
		Node* newNode = new Node(data);
		parent = newNode;
	} else if (data < parent->data) {
		parent->left_child = recursiveAdd(parent->left_child, data);
	} else {
		parent->right_child = recursiveAdd(parent->right_child, data);
	}
	return parent;
}

void BST::find(int data) {
	if (find(root, data)) {
		std::cout << data << " found in tree." << endl;
	} else {
		std::cout << data << " not found in tree." << endl;
	}
}

bool BST::find(Node* parent, int data) {
	if (parent == NULL) {
		return false;
	} else if (data == parent->data) {
		return true;
	} else if (data < parent->data) {
		return find(parent->left_child, data);
	} else {
		return find(parent->right_child, data);
	}
}

bool BST::remove(int data) {
	if (root == NULL) {
		std::cout << data << " tree is empty, remove failed." << endl;
		return false;
	} else if (!find(root, data)) {
		std::cout << data << " not in tree, remove failed."<< endl;
		return false;
	} else {
		root = recursiveRemove(root, data);
		if (!find(root, data)) {
			std::cout << data << " removed successfully." << endl;
			return true;
		} else {
			std::cout << data << " not removed successfully." << endl;
			return false;
		}
	}
}

Node* BST::recursiveRemove(Node* parent, int data) {
	if (data < parent->data) {
		parent->left_child = recursiveRemove(parent->left_child, data);
	} else if (data > parent->data) {
		parent->right_child = recursiveRemove(parent->right_child, data);
	} else if (data == parent->data) {
		if (parent->left_child == NULL && parent->right_child == NULL) {
			// Case 1: leaf node
			delete parent;
			parent = NULL;
		} else if (parent->left_child == NULL) {
			// Case 2: node lacks a left child (no predecessor)
			Node* temp = parent;
			parent = parent->right_child;
			delete temp;
		} else if (getMax(parent->left_child)->left_child == NULL) {
			// Case 3: predecessor to node has no left child
			Node* predecessor = getMax(parent->left_child);
			parent->data = predecessor->data;
			delete predecessor;
		} else if (getMax(parent->left_child)->left_child != NULL) {
			// Case 4: predecessor to node has left child
			Node* predecessor = getMax(parent->left_child);
			parent->data = predecessor->data;
			Node* temp = predecessor;
			predecessor = predecessor->left_child;
			delete temp;
		}
	}
	return parent;
}

Node* BST::getMax(Node* parent) {
	Node* go = parent;
	while (go->right_child != NULL) {
		go = go->right_child;
	}
	return go;
}

void BST::clear() {
	while (root != NULL) {
		root = recursiveRemove(root, root->data);
	}
}