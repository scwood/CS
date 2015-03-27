#include "Node.h"

Node::Node(int new_data) {
	left_child = NULL;
	right_child = NULL;
	height = 0;
	data = new_data;
}

Node::~Node() {}

int Node::getData() {
	return data;
}

int Node::getHeight() {
	return height;
}

NodeInterface* Node::getLeftChild() {
	return left_child;
}

NodeInterface* Node::getRightChild() {
	return right_child;
}