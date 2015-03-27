/*
 * Station.h
 *
 *  Created on: Oct 17, 2014
 *      Author: Spencer
 */

#ifndef STATION_H_
#define STATION_H_

#include "StationInterfaceExtra.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "IRDeque.h"
#include "ORDeque.h"

using namespace std;

class Station : public StationInterfaceExtra {
private:
	int current_car;
	Stack theStack;
	Queue theQueue;
	Deque theDeque;
	IRDeque theIRDeque;
	ORDeque theORDeque;
public:
	Station();
	~Station();

	bool addToStation(int car);
	int showCurrentCar();
	bool removeFromStation();

	bool addToStack();
	bool removeFromStack();
	int showTopOfStack();
	int showSizeOfStack();

	virtual bool addToQueue();
	virtual bool removeFromQueue();
	int showTopOfQueue();
	int showSizeOfQueue();

	bool addToDequeLeft();
	bool addToDequeRight();
	bool removeFromDequeLeft();
	bool removeFromDequeRight();
	int showTopOfDequeLeft();
	int showTopOfDequeRight();
	int showSizeOfDeque();

	bool addToIRDequeLeft();
	bool removeFromIRDequeLeft();
	bool removeFromIRDequeRight();
	int showTopOfIRDequeLeft();
	int showTopOfIRDequeRight();
	int showSizeOfIRDeque();

	bool addToORDequeLeft();
	bool addToORDequeRight();
	bool removeFromORDequeLeft();
	int showTopOfORDequeLeft();
	int showSizeOfORDeque();
};





#endif /* STATION_H_ */
