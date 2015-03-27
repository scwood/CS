/*
 * IRDeque.h
 *
 *  Created on: Oct 22, 2014
 *      Author: scwood
 */
#ifndef IRDEQUE_H_
#define IRDEQUE_H_

#include "LinkedList.h"

using namespace std;

class IRDeque {
private:
	LinkedList<int> list;

public:
	IRDeque();
	~IRDeque();

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


#endif /* IRDeque_H_ */
