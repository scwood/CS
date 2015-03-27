#ifndef QUERY_H_
#define QUERY_H_

#include <string>
#include "predicate.h"

class Query {
public:
  Query();
  ~Query();
  Predicate predicate;
  std::string toString();
};

#endif // QUERY_H_
