#ifndef ANALYZER_H_
#define ANALYZER_H_

#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "tokentype.h"
#include "tokens.h"

class Analyzer {
  public:
    Analyzer();
    ~Analyzer();
    void printTokens(std::string file_name);
    std::vector<Tokens> getParsableTokens(std::string file_name);
  private:
    // DFAs
    void checkComma(std::string input);
    void checkPeriod(std::string input);
    void checkQuestionMark(std::string input);
    void checkLeftParenthesis(std::string input);
    void checkRightParenthesis(std::string input);
    void checkMultiply(std::string input);
    void checkAdd(std::string input);
    void checkColon(std::string input);
    void checkComment(std::string input);
    void checkString(std::string input);
    void checkAlphas(std::string input);
    void checkWhitespace(std::string input);
    // Helper functions
    std::string enumToString(token token_type);
    // Variable declarations
    token current_token;
    int character_count;
    int line_number;
    int extra_carriage_returns;
    int number_of_tokens;
};

#endif // ANALYZER_H_
