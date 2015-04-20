#include "component.h"
#include <sstream>

#define TESTING false

using namespace std;

Component::Component() {
  trivial = false;
  goes_to_self = false;
}

string Component::toString() {
  stringstream result;
  for (int i = 0; i < rules.size() - 1; i++) {
    result << "R" << rules[i] << ",";
  }
  result << "R" << rules.back();
  if (TESTING) {
    result << " Trivial: " << trivial;
  }
  result << "\n";
  return result.str();
}
