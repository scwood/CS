#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <string>
#include "tokentype.h"

class Parameter;

class Expression {
public:
  Expression();
  ~Expression();
  std::string toString();
  Parameter* param_one;
  Parameter* param_two;
  token operator_;
};

#endif // EXPRESSION_H_
