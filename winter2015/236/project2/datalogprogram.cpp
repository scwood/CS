#include "datalogprogram.h"
#include <sstream>
#include <algorithm>

using namespace std;

DatalogProgram::DatalogProgram() {
  scheme_count = 0;
  fact_count = 0;
  rule_count = 0;
  query_count = 0;
  domain_count = 0;
}

DatalogProgram::~DatalogProgram() {}

string DatalogProgram::toString() {
  stringstream result;
  result << "Schemes(" << schemes.size() << "):\n";
  for (unsigned int i = 0; i < schemes.size(); i++) {
    result << "  " << schemes[i].toString();
  }
  result << "Facts(" << facts.size() << "):\n";
  for (unsigned int i = 0; i < facts.size(); i++) {
    result << "  " << facts[i].toString();
  }
  result << "Rules(" << rules.size() << "):\n";
  for (unsigned int i = 0; i < rules.size(); i++) {
    result << "  " << rules[i].toString();
  }
  result << "Queries(" << queries.size() << "):\n";
  for (unsigned int i = 0; i < queries.size(); i++) {
    result << "  " << queries[i].toString();
  }
  sort(domain.begin(), domain.end());
  vector<string>::iterator duplicates = unique(domain.begin(), domain.end());
  domain.erase(duplicates, domain.end());
  result << "Domain(" << domain.size() << "):\n";
  for (unsigned int i = 0; i < domain.size(); i++) {
    result << "  " << domain[i] << "\n";
  }
  return result.str();
}
