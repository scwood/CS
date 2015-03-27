#include "Student.h"
#include <iomanip>
#include <sstream>

Student::Student() {
	ID = 0;
	name = "";
	address = "";
	phone_number = "";
	grade_total = 0;
	number_of_classes = 0;
	GPA = 0;
}

Student::~Student() {}

unsigned long long int Student::getID() {
	return ID;	
}

string Student::getName() {
	return name;
}

string Student::getGPA() {
	GPA = grade_total / number_of_classes;
	stringstream convert;
	convert << GPA;
	string result = convert.str();
	return result; 
}

void Student::addGPA(double classGrade) {
	grade_total += classGrade;
}

string Student::toString() {
	string result = "";
	stringstream ID_string;
	ID_string << ID;
	GPA = grade_total / number_of_classes;
	stringstream GPA_string;
	GPA_string << fixed << setprecision(2) << GPA; 
	result = ID_string.str() + "\n"
		+ name + "\n"
		+ address + "\n"
		+ phone_number + "\n"
		+ GPA_string.str();
	return result;
}