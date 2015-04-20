/*
 * Stack.cpp
 *
 *  Created on: Oct 17, 2014
 *      Author: Spencer
 */

#include "Stack.h"

using namespace std;

Stack::Stack() {}
Stack::~Stack() {}

void Stack::push(int value) {
	list.insertTail(value);
}

void Stack::pop() {
	int tail = list.at(list.size()-1);
	list.remove(tail);
}

int Stack::top() {
	return list.at(list.size()-1);
}

int Stack::size() {
	return list.size();
}

bool Stack::empty() {
	if (list.size() == 0) {
		return true;
	}
	else return false;
}

void Stack::print() {
	list.print();
	return;
}

bool Stack::search(int value) {
	if (list.search(value)) {
		return true;
	}
	else return false;
}
