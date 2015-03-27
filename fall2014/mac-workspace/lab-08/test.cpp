#include <iostream>
#include "QS.h"

using namespace std;

int main() {
	QS test;
	test.createArray(7);
	test.addToArray(10);
	test.addToArray(3);
	test.addToArray(5);
	test.addToArray(9);
	test.addToArray(1);
	test.addToArray(4);
	test.addToArray(4);
	cout << "Before sort: " << test.getArray() << "\n";
	test.sortAll();
	cout << "After sort: " << test.getArray() << "\n";
	}