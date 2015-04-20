/*
 * fighter.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */
#include "fighter.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Fighter::Fighter(string name, string type, int max_hp, int strength, int speed, int magic)
{
	f_name = name;
	f_type = type;
	f_max_hp = max_hp;
	f_strength = strength;
	f_speed = speed;
	f_magic = magic;
	f_current_hp = max_hp;
}
string Fighter::getName()
{
	return f_name;
}
int Fighter::getMaximumHP()
{
	return f_max_hp;
}
int Fighter::getCurrentHP()
{
	return f_current_hp;
}
int Fighter::getStrength()
{
	return f_strength;
}
int Fighter::getSpeed()
{
	return f_speed;
}
int Fighter::getMagic()
{
	return f_magic;
}
int Fighter::getDamage()
{
	return 0;
}
void Fighter::takeDamage(int damage)
{
	int reduction = f_speed / 4;
	damage -= reduction;
	if (damage < 1)
	{
		damage = 1;
	}
	f_current_hp -= damage;
	return;
}
void Fighter::reset()
{
	return;
}
void Fighter::regenerate()
{
	int regenerate = f_strength / 6;
	if (regenerate < 1)
	{
		regenerate = 1;
	}
	f_current_hp += regenerate;
	if (f_current_hp > f_max_hp)
	{
		f_current_hp = f_max_hp;
	}
	return;
}
bool Fighter::useAbility()
{
	return 0;
}
