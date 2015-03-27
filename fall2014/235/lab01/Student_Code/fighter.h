/*
 * figher.h
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */

#ifndef FIGHER_H_
#define FIGHER_H_
#pragma once
#include "FighterInterface.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Fighter: public FighterInterface
{
protected:
	string f_name;
	string f_type;
	int f_max_hp;
	int f_strength;
	int f_speed;
	int f_magic;
	int f_current_hp;

public:
	Fighter(string name, string type, int max_hp, int strength, int speed, int magic);
	~Fighter(){};
	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	void takeDamage(int damage);

	virtual int getDamage();
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility();
};

#endif /* FIGHER_H_ */
