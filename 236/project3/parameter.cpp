#include "parameter.h"
#include <sstream>

using namespace std;

Parameter::Parameter(string contents) {
  this->contents = contents;
  if (contents[0] == '\'') {
    is_string = true;
  } else {
    is_string = false;
  }
}

Parameter::~Parameter() {}

string Parameter::toString() {
  return contents;
}
