/*
 * archer.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */

#include "archer.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Archer::Archer(string name, string type, int max_hp, int strength, int speed, int magic) : Fighter(name, type, max_hp, strength, speed, magic)
{
	max_speed = f_speed;
}

int Archer::getDamage()
{
	return f_speed;
}

void Archer::reset()
{
	f_current_hp = f_max_hp;
	f_speed = max_speed;
	return;
}

bool Archer::useAbility()
{
	f_speed++;
	return 1;
}



