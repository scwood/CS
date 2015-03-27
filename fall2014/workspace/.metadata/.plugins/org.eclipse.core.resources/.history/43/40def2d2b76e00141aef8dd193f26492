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
	Node* recursiveAdd(Node* parent, int data);
	bool add(int data);
	void find(int data);
	bool find(Node* parent, int data);
	bool remove(int data);
	Node* recursiveRemove(Node* parent, int data);
	Node* getMax(Node* parent);
	void clear();
};

#endif