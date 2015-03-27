#ifndef TOKENTYPE_H_
#define TOKENTYPE_H_

#include <string>

enum token {
  COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    WHITESPACE,
    UNDEFINED,
    END_OF_FILE
};

#endif // TOKENTYPE_H_
