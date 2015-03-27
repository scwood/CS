#include "datalogprogram.h"
#include <sstream>

using namespace std;

DatalogProgram::DatalogProgram() {}

DatalogProgram::~DatalogProgram() {}

string DatalogProgram::toString() {
  stringstream result;
  result << "Schemes(" << schemes.size() << "):\n";
  for (int i = 0; i < schemes.size(); i++) {
    result << "  " << schemes[i].toString();
  }
  result << "Facts(" << facts.size() << "):\n";
  for (int i = 0; i < facts.size(); i++) {
    result << "  " << facts[i].toString();
  }
  result << "Rules(" << rules.size() << "):\n";
  for (int i = 0; i < rules.size(); i++) {
    result << "  " << rules[i].toString();
  }
  result << "Queries(" << queries.size() << "):\n";
  for (int i = 0; i < queries.size(); i++) {
    result << "  " << queries[i].toString();
  }
  sort(domain.begin(), domain.end());
  vector<string>::iterator duplicates = unique(domain.begin(), domain.end());
  domain.erase(duplicates, domain.end());
  result << "Domain(" << domain.size() << "):\n";
  for (int i = 0; i < domain.size(); i++) {
    result << "  " << domain[i] << "\n";
  }
  return result.str();
}
