#include "predicate.h"
#include <sstream>
#include <iostream>

using namespace std;

Predicate::Predicate() {
  id = "";
}

Predicate::~Predicate() {}

string Predicate::toString() {
  bool TESTING = true;
  if (TESTING) cout << "\n    Predicate toString started\n";
  stringstream result;
  result << id << "(";
  for (int i = 0; i < parameter_list.size() - 1; i++) {
    result << parameter_list[i].toString() << ",";
  }
  result << parameter_list.back().toString() << ")";
  return result.str();
}
