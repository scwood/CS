/*
 * Station.cpp
 *
 *  Created on: Oct 17, 2014
 *      Author: Spencer
 */

#include "Station.h"

using namespace std;

Station::Station() {
	current_car = -1;
}
Station::~Station() {}

// PART 1
//////////////////////////////////////////////////////////

bool Station::addToStation(int car) {
	if (current_car != -1) {
		return false;
	}
	if (car < 0) {
		return false;
	}
	if (theStack.search(car) || theQueue.search(car) || theDeque.search(car) || theIRDeque.search(car) || theORDeque.search(car)){
		return false;
	}
	current_car = car;
	return true;
}
int Station::showCurrentCar() {
	if (current_car == -1) {
		return -1;
	}
	else return current_car;
}
bool Station::removeFromStation() {
	if (current_car == -1) {
		return false;
	}
	else {
		current_car = -1;
		return true;
	}
}

// STACK - PART 2
//////////////////////////////////////////////////////////

bool Station::addToStack() {
	if (theStack.size() >= 5) {
		return false;
	}
	if (current_car == -1) {
		return false;
	}
	theStack.push(current_car);
	current_car = -1;
	return true;
}
bool Station::removeFromStack() {
	if (current_car != -1) {
		return false;
	}
	if (theStack.empty()) {
		return false;
	}
	current_car = theStack.top();
	theStack.pop();
	return true;
}
int Station::showTopOfStack() {
	if (theStack.empty()) {
		return -1;
	}
	return theStack.top();
}
int Station::showSizeOfStack() {
	return theStack.size();
}

// QUEUE - PART 3
//////////////////////////////////////////////////////////

bool Station::addToQueue() {
	if (theQueue.size() >= 5) {
		return false;
	}
	if (current_car == -1) {
		return false;
	}
	theQueue.push(current_car);
	current_car = -1;
	return true;
}
bool Station::removeFromQueue() {
	if (current_car != -1) {
		return false;
	}
	if (theQueue.empty()) {
		return false;
	}
	current_car = theQueue.top();
	theQueue.pop();
	return true;
}
int Station::showTopOfQueue() {
	if (theQueue.empty()) {
		return -1;
	}
	return theQueue.top();
}
int Station::showSizeOfQueue() {
	return theQueue.size();
}

// DEQUE - PART 4
//////////////////////////////////////////////////////////

bool Station::addToDequeLeft() {
	if (theDeque.size() >= 5) {
		return false;
	}
	if (current_car == -1) {
		return false;
	}
	theDeque.pushLeft(current_car);
	current_car = -1;
	return true;
}
bool Station::addToDequeRight() {
	if (theDeque.size() >= 5) {
		return false;
	}
	if (current_car == -1) {
		return false;
	}
	theDeque.pushRight(current_car);
	current_car = -1;
	return true;
}
bool Station::removeFromDequeLeft() {
	if (current_car != -1) {
		return false;
	}
	if (theDeque.empty()) {
		return false;
	}
	current_car = theDeque.topLeft();
	theDeque.popLeft();
	return true;
}
bool Station::removeFromDequeRight() {
	if (current_car != -1) {
		return false;
	}
	if (theDeque.empty()) {
		return false;
	}
	current_car = theDeque.topRight();
	theDeque.popRight();
	return true;
}
int Station::showTopOfDequeLeft() {
	if (theDeque.empty()) {
		return -1;
	}
	return theDeque.topLeft();
}
int Station::showTopOfDequeRight() {
	if (theDeque.empty()) {
		return -1;
	}
	return theDeque.topRight();
}
int Station::showSizeOfDeque() {
	return theDeque.size();
}

// IRDEQUE - PART 5
//////////////////////////////////////////////////////////

bool Station::addToIRDequeLeft() {
	if (theIRDeque.size() >= 5) {
		return false;
	}
	if (current_car == -1) {
		return false;
	}
	theIRDeque.pushLeft(current_car);
	current_car = -1;
	return true;
}
bool Station::removeFromIRDequeLeft() {
	if (current_car != -1) {
		return false;
	}
	if (theIRDeque.empty()) {
		return false;
	}
	current_car = theIRDeque.topLeft();
	theIRDeque.popLeft();
	return true;
}
bool Station::removeFromIRDequeRight() {
	if (current_car != -1) {
		return false;
	}
	if (theIRDeque.empty()) {
		return false;
	}
	current_car = theIRDeque.topRight();
	theIRDeque.popRight();
	return true;
}
int Station::showTopOfIRDequeLeft() {
	if (theIRDeque.empty()) {
		return -1;
	}
	return theIRDeque.topLeft();
}
int Station::showTopOfIRDequeRight() {
	if (theIRDeque.empty()) {
		return -1;
	}
	return theIRDeque.topRight();
}
int Station::showSizeOfIRDeque() {
	return theIRDeque.size();
}

// ORDEQUE - PART 6
//////////////////////////////////////////////////////////

bool Station::addToORDequeLeft() {
	if (theORDeque.size() >= 5) {
		return false;
	}
	if (current_car == -1) {
		return false;
	}
	theORDeque.pushLeft(current_car);
	current_car = -1;
	return true;
}
bool Station::addToORDequeRight() {
	if (theORDeque.size() >= 5) {
		return false;
	}
	if (current_car == -1) {
		return false;
	}
	theORDeque.pushRight(current_car);
	current_car = -1;
	return true;
}
bool Station::removeFromORDequeLeft() {
	if (current_car != -1) {
		return false;
	}
	if (theORDeque.empty()) {
		return false;
	}
	current_car = theORDeque.topLeft();
	theORDeque.popLeft();
	return true;
}
int Station::showTopOfORDequeLeft() {
	if (theORDeque.empty()) {
		return -1;
	}
	return theORDeque.topLeft();
}
int Station::showSizeOfORDeque() {
	return theORDeque.size();
}
