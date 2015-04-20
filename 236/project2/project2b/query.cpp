#include "query.h"
#include <sstream>

using namespace std;

Query::Query() {}

Query::~Query() {}

string Query::toString() {
  stringstream result;
  result << predicate.toString() << "?\n";
  return result.str();
}
