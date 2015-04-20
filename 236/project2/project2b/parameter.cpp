#include "parameter.h"
#include <sstream>

using namespace std;

Parameter::Parameter() {}

Parameter::~Parameter() {}

string Parameter::toString() {
  return contents;
}
