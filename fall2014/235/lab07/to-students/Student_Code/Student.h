#ifndef STUDENT_H_
#define STUDENT_H_

#include "StudentInterface.h"

class Student : public StudentInterface {
public:
	Student();
	~Student();

	// methods
	unsigned long long int getID();
	string getName();
	string getGPA();
	void addGPA(double classGrade);
	string toString();

	// data members
	unsigned long long int ID;
	string name;
	string address;
	string phone_number;
	int grade_total;
	int number_of_classes;
	double GPA;
};

#endif // STUDENT_H_