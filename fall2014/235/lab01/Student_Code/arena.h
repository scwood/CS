/*
 * arena.h
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */

#ifndef ARENA_H_
#define ARENA_H_
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"
#include "fighter.h"
#include "ArenaInterface.h"
using namespace std;

class Arena: public ArenaInterface
{
private:
	vector<Fighter*> collection;
public:
	Arena(){};
	~Arena(){};
	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();
};

#endif /* ARENA_H_ */
