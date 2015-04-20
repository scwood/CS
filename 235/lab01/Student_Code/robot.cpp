/*
 * robot.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */

#include "robot.h"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

Robot::Robot(string name, string type, int max_hp, int strength, int speed, int magic) : Fighter(name, type, max_hp, strength, speed, magic)
{
	electricity = 2 * magic;
	current_electricity = electricity;
	bonus_damage = 0;
}

int Robot::getDamage()
{
	int robot_damage = f_strength + bonus_damage;
	bonus_damage = 0;
	return robot_damage;
}

void Robot::reset()
{
	f_current_hp = f_max_hp;
	electricity = 2 * f_magic;
	bonus_damage = 0;
	return;
}

/*	Robot: Shockwave Punch
		 *	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
		 *	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
		 *	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
		 *		Examples:
		 *		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
		 *		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
		 *		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
		 *		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
		 *	Robot Note:
		 *	The bonus damage formula should be computed using double arithmetic, and only
		 *	the final result should be cast into an integer.*/

bool Robot::useAbility()
{
	if (current_electricity < ROBOT_ABILITY_COST)
	{
		return 0;
	}

	double r_strength = f_strength * 1.0;
	double r_current_electricity = current_electricity * 1.0;
	double r_electricity = electricity * 1.0;
	double b_damage = r_current_electricity / r_electricity;
	b_damage = pow(b_damage, 4);
	b_damage = b_damage * r_strength;

	bonus_damage = b_damage;

	current_electricity -= ROBOT_ABILITY_COST;

	return 1;
}
