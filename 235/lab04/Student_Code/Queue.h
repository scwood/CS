/*
 * Queue.h
 *
 *  Created on: Oct 17, 2014
 *      Author: Spencer
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "LinkedList.h"

using namespace std;

class Queue {
private:
	LinkedList<int> list;
public:
	int push(int value);
	int top();
	int size();
	void pop();
	void print();
	bool empty();
	bool search(int value);
};
#endif /* QUEUE_H_ */
