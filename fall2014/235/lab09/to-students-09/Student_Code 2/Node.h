#ifndef NODE_H_
#define NODE_H_

#include "NodeInterface.h"

class Node : public NodeInterface {
public:
	Node(int new_data);
	~Node();

	// methods
	int getData();
	int getHeight();
	NodeInterface* getLeftChild();
	NodeInterface* getRightChild();

	// data members
	Node* left_child;
	Node* right_child;
	int height;
	int data;
};

#endif // NODE_H_