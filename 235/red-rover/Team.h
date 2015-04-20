// Spencer Wood
// CS 235 Fall 2014 Midterm

#ifndef TEAM_H_
#define TEAM_H_

#include "Person.h"

using namespace std;

class Team {
public:
	Person* head;
	int size;
	Team();
	~Team();
	void printTeam();
	void printInfo();
	void shuffleTeam();
	void addHeadPerson(string name, int strength, int speed);
	void removeHeadPerson();
	void remove(string name);
	void insertAfter(string name, string newName, int strength, int speed);
	void insertBetween(string name, string newName, int strength, int speed);
	void clear();
	string headName();
	string nextName(string name);
	string getRandomPerson();
	int headStrength();
	int headSpeed();
	int strengthAt(string name);
	int speedAt(string name);
	int getSize();
	bool search(string name);
	bool empty();
};

#endif