#include "rule.h"
#include <sstream>

using namespace std;

Rule::Rule() {}

Rule::~Rule() {}

string Rule::toString() {
  stringstream result;
  result << head.toString() << " :- ";
  for (int i = 0; i < predicate_list.size() - 1; i++) {
    result << predicate_list[i].toString() << ",";
  }
  result << predicate_list.back().toString() << ".\n";
  return result.str();
}
