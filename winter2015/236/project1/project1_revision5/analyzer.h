#ifndef ANALYZER_H_
#define ANALYZER_H_

#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Analyzer {
public:
  Analyzer();
  ~Analyzer();
  void printTokens(string file_name);
private:
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
  // DFAs
  void checkComma(string input);
  void checkPeriod(string input);
  void checkQuestionMark(string input);
  void checkLeftParenthesis(string input);
  void checkRightParenthesis(string input);
  void checkMultiply(string input);
  void checkAdd(string input);
  void checkColon(string input);
  void checkComment(string input);
  void checkString(string input);
  void checkAlphas(string input);
  void checkWhitespace(string input);
  // Helper functions
  string enumToString(token tokenType);
  // Variable declarations
  token current_token;
  int character_count;
  int line_number;
  int extra_carriage_returns;
  int number_of_tokens;
};

#endif // ANALYZER_H_
