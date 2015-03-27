#include <iostream>


/**
 * Calculates a Fibonacci sequence of a given term
 *
 * @param   n  user given term
 *
 * @return     the answer
 */
long long fibonacci(long long n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return (fibonacci(n - 1) + (fibonacci(n - 2))); 
	}
}

int main() {
	long long n;
	std::cout << "n = ";
	std::cin >> n;
	while (n < 1) {
		std::cout << "Please enter a positive integer: ";
		std::cin >> n;
	}
	long long result = fibonacci(n);
	std::cout << "Fibonacci sequence a (" << n << ") = " << result << "\n";
	return 0;
}