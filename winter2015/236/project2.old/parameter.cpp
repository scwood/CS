#include "parameter.h"
#include <iostream>
#include <sstream>
#include "expression.h"

using namespace std;

Parameter::Parameter() {
  is_expression = false;
  contents = "";
}

Parameter::~Parameter() {}

string Parameter::toString() {
  bool TESTING = true;
  if (TESTING) cout << "\n    Paramter toString started\n";
  /* if (TESTING) { */
  /*   if (is_expression) cout << "    Param is expression\n"; */
  /* } */
  if (is_expression) {
    if (TESTING) cout << "    Parameter: " << expression->toString();
    return expression->toString();
  }
  else {
    if (TESTING) cout << "    Parameter: " << contents;
    return contents;
  }
}
