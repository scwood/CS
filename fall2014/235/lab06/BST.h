#ifndef BST_H_
#define BST_H_

#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface {
public:
	BST();
	~BST();
	Node* root;
	NodeInterface* getRootNode();
	bool add(int data);
	Node* recursiveAdd(Node* parent, int data);
	void find(int data);
	bool find(Node* parent, int data);
	bool remove(int data);
	Node* recursiveRemove(Node* parent, int data);
	Node* replaceIOP(Node* current, Node* parent);
	void clear();
};

#endif
