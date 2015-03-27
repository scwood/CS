#include <iostream>

using namespace std;

/// Calculates x^n 
int exponent(int x, int n) {
   if (n == 0) {
      return 1;
   }
   else return x * exponent(x, n-1);
}
int main() {
   int x;
   int n;
   cout << "------------------------------" << endl;
   cout << "x term = ";
   cin >> x;
   cout << "n term = ";
   cin >> n;
   cout << x << "^" << n << " = " << exponent(x,n) << endl;
   cout << "------------------------------" << endl;
   return 0;
}



