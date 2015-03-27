/*
 * cleric.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */

#include "cleric.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Cleric::Cleric(string name, string type, int max_hp, int strength, int speed, int magic) : Fighter(name, type, max_hp, strength, speed, magic)
{
	mana = 5 * f_magic;
	current_mana = mana;
}

int Cleric::getDamage()
{
	return f_magic;
}

void Cleric::reset()
{
	f_current_hp = f_max_hp;
	mana = 5 * f_magic;
	return;
}

bool Cleric::useAbility()
{
	if (current_mana < CLERIC_ABILITY_COST)
	{
		return 0;
	}

	int healing_light = f_magic / 3;

	if (healing_light < 1)
	{
		healing_light = 1;
	}

	f_current_hp += healing_light;

	if (f_current_hp > f_max_hp)
	{
		f_current_hp = f_max_hp;
	}

	current_mana -= CLERIC_ABILITY_COST;

	return 1;
}

void Cleric::regenerate()
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

	int mana_regen = f_magic / 5;

	if (mana_regen < 1)
	{
		mana_regen = 1;
	}
	current_mana += mana_regen;
	if (current_mana > mana)
	{
		current_mana = mana;
	}

	return;
}


