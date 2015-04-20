/*
 * arena.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: scwood
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "FighterInterface.h"
#include "arena.h"
#include "fighter.h"
#include "ArenaInterface.h"
#include "archer.h"
#include "cleric.h"
#include "robot.h"

using namespace std;

bool Arena::addFighter(string info)
{
	string name;
	string type;
	int max_hp;
	int strength;
	int speed;
	int magic;

	stringstream parse(info);
	parse >> name >> type >> max_hp >> strength >> speed >> magic;

	if (parse.fail()) // Check for correct variables, and for a too short of an input
	{
		return 0;
	}
	if (!parse.eof()) // Check for too long of an input
	{
		return 0;
	}

	string name_check = name;
	int size = collection.size();

	for (int i = 0; i < size; i++) // Check for existing name
	{
		if (name_check == collection[i]->getName())
		{
			return 0;
		}
	}

	if (type != "A" && type != "C" && type != "R") // Check for correct type
	{
		return 0;
	}

	if (max_hp <= 0 || strength <= 0 || speed <= 0 || magic <= 0) // Check for non positive ints
	{
		return 0;
	}

	if (type == "A") // Archer construct
	{
		collection.push_back(new Archer(name, type, max_hp, strength, speed, magic));
	}

	else if (type == "C") // Cleric construct
	{
		collection.push_back(new Cleric(name, type, max_hp, strength, speed, magic));
	}

	else if (type == "R") // Robot construct
	{
		collection.push_back(new Robot(name, type, max_hp, strength, speed, magic));
	}

	return 1;
}

bool Arena::removeFighter(string name)
{
	string name_check = name;
	int size = collection.size();
	for (int i = 0; i < size; i++)
	{
		if (name_check == collection[i]->getName())
		{
			collection.erase(collection.begin()+i);
			return 1;
		}
	}

	return 0;
}


FighterInterface* Arena::getFighter(string name)
{
	string name_check = name;
	int size = collection.size();
	for (int i = 0; i < size; i++)
	{
		if (name_check == collection[i]->getName())
		{
			return collection[i];
		}
	}

	return NULL;
}

int Arena::getSize()
{
	return collection.size();
}
