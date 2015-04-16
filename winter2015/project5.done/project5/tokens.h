#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include "tokentype.h"

class Tokens {
  public:
    Tokens();
    ~Tokens();
    std::string toString();
    std::string enumToString(token token_type);
    token type;
    std::string contents;
    int line_number;
};

#endif // TOKEN_H_
