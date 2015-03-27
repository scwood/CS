#ifndef PREDICATE_H_
#define PREDICATE_H_ 

#include <string>
#include <vector>
#include "parameter.h"


class Predicate {
public:
  Predicate();
  ~Predicate();
  std::string toString();
  std::string id;
  std::vector<Parameter> parameter_list;
};

#endif // PREDICATE_H_
