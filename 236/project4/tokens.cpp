#include "tokens.h"
#include <sstream>

using namespace std;

Tokens::Tokens() {
  type = UNDEFINED;
  contents = "";
  line_number = 0;
}

string Tokens::toString() {
  stringstream result;
  result 
    << "(" 
    << enumToString(type) 
    << ",\"" << contents 
    << "\"," 
    << line_number 
    << ")\n";
  return result.str();
}

string Tokens::enumToString(token token_type) {
  switch(token_type) {
    case COMMA:
      return "COMMA";
    case PERIOD:
      return "PERIOD";
    case Q_MARK:
      return "Q_MARK";
    case LEFT_PAREN:
      return "LEFT_PAREN";
    case RIGHT_PAREN:
      return "RIGHT_PAREN";
    case COLON:
      return "COLON";
    case COLON_DASH:
      return "COLON_DASH";
    case MULTIPLY:
      return "MULTIPLY";
    case ADD:
      return "ADD";
    case SCHEMES:
      return "SCHEMES";
    case FACTS:
      return "FACTS";
    case RULES:
      return "RULES";
    case QUERIES:
      return "QUERIES";
    case ID:
      return "ID";
    case STRING:
      return "STRING";
    case COMMENT:
      return "COMMENT";
    case WHITESPACE:
      // to suppress compiler warning
      return "";
    case UNDEFINED:
      return "UNDEFINED";
    case END_OF_FILE:
      return "EOF";
  }
  return "";
}
Tokens::~Tokens() {}
