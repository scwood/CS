/*
 * Deque.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: scwood
 */

#include "Deque.h"

using namespace std;

Deque::Deque() {}
Deque::~Deque() {}

void Deque::pushLeft(int value) {
	list.insertHead(value);
}
void Deque::pushRight(int value) {
	list.insertTail(value);
}
void Deque::popLeft() {
	int head = list.at(0);
	list.remove(head);
}
void Deque::popRight() {
	int tail = list.at(list.size()-1);
	list.remove(tail);
}
int Deque::topLeft() {
	return list.at(0);
}
int Deque::topRight() {
	return list.at(list.size()-1);
}
int Deque::size() {
	return list.size();
}
bool Deque::empty() {
	if (list.size() == 0) {
		return true;
	}
	else return false;
}
bool Deque::search(int value) {
	if (list.search(value)) {
		return true;
	}
	else return false;
}
