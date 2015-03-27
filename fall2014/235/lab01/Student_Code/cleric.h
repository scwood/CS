/*
 * cleric.h
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */

#ifndef CLERIC_H_
#define CLERIC_H_
#include "fighter.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cleric: public Fighter
{

private:
	int mana;
	int current_mana;

public:
	Cleric(string name, string type, int max_hp, int strength, int speed, int magic);
	~Cleric(){};
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
};




#endif /* CLERIC_H_ */
