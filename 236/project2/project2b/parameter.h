#ifndef PARAMETER_H_
#define PARAMETER_H_

#include <string>

class Parameter {
public:
  Parameter();
  ~Parameter();
  std::string toString();
  std::string contents;
};

#endif // PARAMETER_H_
