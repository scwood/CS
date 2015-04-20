#include "fact.h"
#include <sstream>

using namespace std;

Fact::Fact() {
	id = "";
}

Fact::~Fact() {} 

string Fact::toString() {
  stringstream result;
  result << id << "(";
  for (unsigned int i = 0; i < string_list.size() - 1; i++) {
    result << string_list[i] << ",";
  }
  result << string_list.back() << ").\n";
  return result.str();
}
