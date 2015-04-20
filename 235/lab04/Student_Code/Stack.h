/*
 * Stack.h
 *
 *  Created on: Oct 17, 2014
 *      Author: Spencer
 */

#ifndef STACK_H_
#define STACK_H_

#include "LinkedList.h"

using namespace std;

class Stack {
private:
	LinkedList<int> list;

public:
	Stack();
	~Stack();

	void push(int value);
	void pop();
	int top();
	int size();
	bool empty();
	void print();
	bool search(int value);
};




#endif /* STACK_H_ */
