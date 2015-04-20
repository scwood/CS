#ifndef PARAMETER_H_
#define PARAMETER_H_

#include <string>

class Parameter {
  public:
    Parameter(std::string contents);
    ~Parameter();
    std::string toString();
    std::string contents;
    bool is_string;
};

#endif // PARAMETER_H_
