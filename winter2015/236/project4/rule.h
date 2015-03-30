#ifndef RULE_H_
#define RULE_H_

#include <string>
#include <vector>
#include "predicate.h"

class Rule {
public:
  Rule();
  ~Rule();
  Predicate head;
  std::vector<Predicate> predicate_list;
  std::string toString();
};

#endif // RULE_H_
