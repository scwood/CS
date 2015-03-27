#include "expression.h"
#include <iostream>
#include <sstream>
#include "parameter.h"

using namespace std;

Expression::Expression() {}

Expression::~Expression() {}

string Expression::toString() {
  /* bool TESTING = true; */
  /* if (TESTING) cout << "    Expression toString started\n"; */
  stringstream result;
  result << "(" << param_one->toString();
  if (operator_ == ADD) {
    result << "+";
  } else {
    result << "*";
  }
  result << param_two->toString() << ")";
  /* if (TESTING) cout << "    Expression: " << result.str(); */
  return result.str();
}
