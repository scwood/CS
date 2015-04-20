#include "to-students-09/Student_Code/AVL.h"
#include <iostream>

int main() {
	AVL test;
	test.add(20);
	test.add(10);
	test.add(30);
	test.add(5);
	test.add(40);
	test.add(15);
	test.add(25);
	test.add(12);
	test.add(28);
	test.add(35);
	test.add(45);
	test.add(50);
	test.remove(5);
	test.preOrderPrint();
	return 0;
}