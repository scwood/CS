/*
 * ORDeque.h
 *
 *  Created on: Oct 22, 2014
 *      Author: scwood
 */

#ifndef ORDEQUE_H_
#define ORDEQUE_H_

#include "LinkedList.h"

using namespace std;

class ORDeque {
private:
	LinkedList<int> list;

public:
	ORDeque();
	~ORDeque();

	void pushLeft(int value);
	void pushRight(int value);
	void popLeft();
	int topLeft();
	int size();
	bool empty();
	bool print();
	bool search(int value);
};




#endif /* ORDEQUE_H_ */
