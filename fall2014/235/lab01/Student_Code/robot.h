/*
 * robot.h
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */

#ifndef ROBOT_H_
#define ROBOT_H_
#pragma once
#include "fighter.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Robot: public Fighter
{

private:
	int electricity;
	int current_electricity;
	int bonus_damage;

public:
	Robot(string name, string type, int max_hp, int strength, int speed, int magic);
	~Robot(){};
	int getDamage();
	void reset();
	bool useAbility();
};

#endif /* ROBOT_H_ */
