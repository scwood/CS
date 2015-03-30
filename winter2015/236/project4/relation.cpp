#include "relation.h"
#include <string>
#include <sstream>

using namespace std;

string Relation::toString() {
  stringstream result;
  result << id << "\n";
  for (int i = 0; i < tuples.size(); i++) {
    for (int j = 0; j < tuples[i].size() ; j++) {
      result << tuples[i][j] << ",";
    }
    result << "\n";
  }
  return result.str();
}
