/*
 * test.cpp
 *
 *  Created on: Oct 20, 2014
 *      Author: Spencer
 */

#include <iostream>
#include <string>

using namespace std;

int factorial(int number) {
	if (number == 0) {
		return 1;
	}
	else {
		return number * factorial(number-1);
	}
}

int xN(double x, int power) {
	if (power == 0) {
		return 1;
	}
	else {
		return x * xN(x, power-1);
	}
}

int GCD(int m, int n) {
	if (m % n == 0) {
		return n;
	}
	if (m < n) {
		return GCD(n, m);
	}
	else {
		return GCD(n, m % n);
	}
}


int main() {

	cout << "4! = " << factorial(4) << endl;

	cout << "2^3 = " << xN(2, 3) << endl;

	cout << "GCD of 24 and 4 is " << GCD(24, 4) << endl;

	return 0;
}
