#include "Node.h"

Node::Node(int value) {
	data = value;
}

Node::~Node() {}

int Node::getData() {
	return data;
}

NodeInterface * Node::getLeftChild() {
	return leftChild;
}

NodeInterface * Node::getRightChild() {
	return rightChild;
}