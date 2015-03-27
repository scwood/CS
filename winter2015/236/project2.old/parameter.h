#ifndef PARAMETER_H_
#define PARAMETER_H_

#include <string>

class Expression;

class Parameter {
public:
  Parameter();
  ~Parameter();
  std::string toString();
  std::string contents;
  Expression* expression;
  bool is_expression;
};

#endif // PARAMETER_H_
