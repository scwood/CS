/*
 * Queue.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: Spencer
 */

#include "Queue.h"

int Queue::push(int value) {
	list.insertHead(value);
	return 0;
}
int Queue::top() {
	return list.at(list.size()-1);
}
int Queue::size() {
	return list.size();
}
void Queue::pop() {
	int tail = list.at(list.size()-1);
	list.remove(tail);
	return;
}
bool Queue::empty() {
	if (list.size() == 0) {
		return true;
	}
	else return false;
}
void Queue::print() {
	list.print();
	return;
}
bool Queue::search(int value) {
	if (list.search(value)) {
		return true;
	}
	else return false;
}
