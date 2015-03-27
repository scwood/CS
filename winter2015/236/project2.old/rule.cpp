#include "rule.h"
#include <sstream>
#include <iostream>

using namespace std;

string Rule::toString() {
  /* bool TESTING = true; */
  /* if (TESTING) cout << "    Rule toString started\n"; */
  stringstream result;
  result << head.toString() << " :- ";
  for (int i = 0; i < predicate_list.size() - 1; i++) {
    result << predicate_list[i].toString() << ",";
  }
  result << predicate_list.back().toString() << ".\n";
  /* if (TESTING) cout << "    Rule: " << result.str(); */
  return result.str();
}
