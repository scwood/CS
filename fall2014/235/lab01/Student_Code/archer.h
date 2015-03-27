/*
 * archer.h
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */

#ifndef ARCHER_H_
#define ARCHER_H_
#include "fighter.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Archer: public Fighter
{
private:
	int max_speed;

public:
	Archer(string name, string type, int max_hp, int strength, int speed, int magic);
	~Archer(){};
	int getDamage();
	void reset();
	bool useAbility();
};






#endif /* ARCHER_H_ */
