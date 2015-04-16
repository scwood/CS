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
  if (schemes.size() > 0) {
    result << "Schemes(" << schemes.size() << "):\n";
    for (unsigned int i = 0; i < schemes.size(); i++) {
      result << "  " << schemes[i].toString();
    }
  }
  if (facts.size() > 0) {
    result << "Facts(" << facts.size() << "):\n";
    for (unsigned int i = 0; i < facts.size(); i++) {
      result << "  " << facts[i].toString();
    }
  }
  if (rules.size() > 0) {
    result << "Rules(" << rules.size() << "):\n";
    for (unsigned int i = 0; i < rules.size(); i++) {
      result << "  " << rules[i].toString();
    }
  }
  if (queries.size() > 0) {
    result << "Queries(" << queries.size() << "):\n";
    for (unsigned int i = 0; i < queries.size(); i++) {
      result << "  " << queries[i].toString();
    }
  }
  if (domain.size() > 0) {
    sort(domain.begin(), domain.end());
    vector<string>::iterator duplicates = unique(domain.begin(), domain.end());
    domain.erase(duplicates, domain.end());
    result << "Domain(" << domain.size() << "):\n";
    for (unsigned int i = 0; i < domain.size(); i++) {
      result << "  " << domain[i] << "\n";
    }
  }
  return result.str();
}
