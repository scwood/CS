#ifndef PARSER_H_
#define PARSER_H_

#include <vector>
#include "datalogprogram.h"
#include "tokens.h"

class Parser {
public:
  Parser();
  ~Parser();
  void parseTokens(std::vector<Tokens> input);
  DatalogProgram program;
private:
  enum SectionName {
    SCHEME, FACT, RULE_HEAD, RULE_LIST, QUERY, EXPRESSION
  };
  token peek();
  // productions
  bool datalogProgram();
  bool scheme();
  bool schemeList();
  bool idList();
  bool fact();
  bool factList();
  bool rule();
  bool ruleList();
  bool headPredicate();
  bool predicate();
  bool predicateList();
  bool parameter();
  bool parameterList();
  bool expression();
  bool checkOperator();
  bool query();
  bool queryList();
  bool stringList();
  // terminals
  bool matchSchemes();
  bool matchFacts();
  bool matchRules();
  bool matchQueries();
  bool matchID();
  bool matchString();
  bool matchLeftParen();
  bool matchRightParen();
  bool matchPeriod();
  bool matchComma();
  bool matchAdd();
  bool matchMultiply();
  bool matchColon();
  bool matchColonDash();
  bool matchQMark();
  // data members
  std::vector<Tokens> token_list;
  std::vector<Tokens> parsed_tokens;
  std::vector<Predicate> parsed_predicates;
  std::vector<std::string> parsed_strings;
  SectionName section;
  int nested_parenthesis;
};

#endif // PARSER_H_
