/*
 * Deque.h
 *
 *  Created on: Oct 22, 2014
 *      Author: scwood
 */

#ifndef DEQUE_H_
#define DEQUE_H_

#include "LinkedList.h"

using namespace std;

class Deque {
private:
	LinkedList<int> list;

public:
	Deque();
	~Deque();

	void pushLeft(int value);
	void pushRight(int value);
	void popLeft();
	void popRight();
	int topLeft();
	int topRight();
	int size();
	bool empty();
	bool print();
	bool search(int value);
};



#endif /* DEQUE_H_ */
