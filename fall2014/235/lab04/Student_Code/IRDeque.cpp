/*
 * IRIRDeque.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: scwood
 */

#include "IRDeque.h"

using namespace std;

IRDeque::IRDeque() {}
IRDeque::~IRDeque() {}

void IRDeque::pushLeft(int value) {
	list.insertHead(value);
}
void IRDeque::popLeft() {
	int head = list.at(0);
	list.remove(head);
}
void IRDeque::popRight() {
	int tail = list.at(list.size()-1);
	list.remove(tail);
}
int IRDeque::topLeft() {
	return list.at(0);
}
int IRDeque::topRight() {
	return list.at(list.size()-1);
}
int IRDeque::size() {
	return list.size();
}
bool IRDeque::empty() {
	if (list.size() == 0) {
		return true;
	}
	else return false;
}
bool IRDeque::search(int value) {
	if (list.search(value)) {
		return true;
	}
	else return false;
}



