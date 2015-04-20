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
  std::string toStringNoNewLine();
};

#endif // QUERY_H_
