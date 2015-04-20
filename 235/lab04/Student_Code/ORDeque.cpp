/*
 * ORORDeque.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: scwood
 */

#include "ORDeque.h"

using namespace std;

ORDeque::ORDeque() {}
ORDeque::~ORDeque() {}

void ORDeque::pushLeft(int value) {
	list.insertHead(value);
}
void ORDeque::pushRight(int value) {
	list.insertTail(value);
}
void ORDeque::popLeft() {
	int head = list.at(0);
	list.remove(head);
}
int ORDeque::topLeft() {
	return list.at(0);
}
int ORDeque::size() {
	return list.size();
}
bool ORDeque::empty() {
	if (list.size() == 0) {
		return true;
	}
	else return false;
}
bool ORDeque::search(int value) {
	if (list.search(value)) {
		return true;
	}
	else return false;
}
