#include <iostream>
#include "to-students/Student_Code/Student.h"
#include "to-students/Student_Code/GPA.h"

using namespace std;

int main() {
	GPA hello;
	bool test = hello.importStudents("to-students/Files/classListMap_Small.txt",
		"to-students/Files/classListSet_Small.txt");
	if (test == false) {
		cout << "Failed." << "\n";
	}
	return 0;
}