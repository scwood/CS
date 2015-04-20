#include "Node.h"

Node::Node(int value) {
	data = value;
	left_child = NULL;
	right_child = NULL;
}

Node::~Node() {}

int Node::getData() {
	return data;
}

NodeInterface* Node::getLeftChild() {
	return left_child;
}

NodeInterface* Node::getRightChild() {
	return right_child;
}