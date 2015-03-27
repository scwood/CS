// Spencer Wood
// CS 235 Fall 2014 Midterm

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

using namespace std;

class Person {
public:
	string name;
	int strength;
	int speed;
	Person* leftPerson;
	Person* rightPerson;
	Person(string the_name, int the_strength, int the_speed);
	~Person();
};

#endif 