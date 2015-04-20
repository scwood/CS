#include "parser.h"
#include <iostream>
#define TESTING false

using namespace std;

Parser::Parser() {
  section = SCHEME;
  nested_parenthesis = 0;
}

Parser::~Parser() {}

void Parser::parseTokens(vector<Tokens> input) {
  token_list = input;
  if (datalogProgram() == true) {
    cout << "Success!\n" << program.toString();
  } else {
    cout << "Failure!\n  " << token_list[0].toString();
  }
}

DatalogProgram Parser::getProgram(vector<Tokens> input) {
  token_list = input;
  if (datalogProgram() == true) {
    datalogProgram();
    return program;
  } else {
    cout << "Failure!\n  " << token_list[0].toString();
    DatalogProgram empty;
    return empty;
  }
}

token Parser::peek() {
  return token_list[0].type;
}

bool Parser::datalogProgram() {
  bool success = false;
  if (peek() == SCHEMES) {
    if (TESTING) cout << "datalogProgram check started...\n";
    success = matchSchemes() && matchColon() && scheme() && schemeList() &&
      matchFacts() && matchColon() && factList() && matchRules() &&
      matchColon() && ruleList() && matchQueries() && matchColon() &&
      query() && queryList();
  } else {
    if (TESTING) cout << "  mismatch: expected SCHEMES\n";
  }
  return success;
}

bool Parser::scheme() {
  bool success = false;
  if (peek() == ID) {
    if (TESTING) cout << "scheme check started...\n";
    success = matchID() && matchLeftParen() && matchID() && idList() && 
      matchRightParen();
  } else {
    if (TESTING) cout << "  mismatch: expected ID\n";
  }
  return success;
}

bool Parser::schemeList() {
  bool success = false;
  if (peek() == FACTS) {
    success = true;
  } else if (peek() == ID) {
    if (TESTING) cout << "schemeList check started...\n";
    success = scheme() && schemeList();
  } else {
   if (TESTING) cout << "  mismatch: expected FACTS or ID\n";
  }
  return success;
}

bool Parser::idList() {
  bool success = false;
  if (peek() == RIGHT_PAREN) {
    success = true;
  } else if (peek() == COMMA) {
    if (TESTING) cout << "idList check started...\n";
    success = matchComma() && matchID() && idList();
  } else {
    if (TESTING) cout << "  mismatch: expected ) or ,\n";
  }
  return success;
}

bool Parser::fact() {
  bool success = false;
  if (peek() == ID) {
    if (TESTING) cout << "fact check started...\n";
    success = matchID() && matchLeftParen() && matchString() && stringList() &&
      matchRightParen() && matchPeriod();
  } else {
    if (TESTING) cout << "  mismatch: expected ID\n";
  }
  return success;
}

bool Parser::factList() {
  bool success = false;
  if (peek() == RULES) {
    success = true;
  } else if (peek() == ID) {
    if (TESTING) cout << "factList check started...\n";
    success = fact() && factList();
  } else {
    if (TESTING) cout << "  mismatch: expected RULES or ID\n";
  }
  return success;
}

bool Parser::rule() {
  bool success = false;
  if (peek() == ID) {
    if (TESTING) cout << "rule check started...\n";
    success = headPredicate() && matchColonDash() && predicate() &&
      predicateList() && matchPeriod();
  } else {
    if (TESTING) cout << "  mismatch: expected ID\n";
  }
  return success;
}

bool Parser::ruleList() {
  bool success = false;
  if (peek() == QUERIES) {
    success = true;
  } else if (peek() == ID) {
    if (TESTING) cout << "ruleList check started...\n";
    success = rule() && ruleList();
  } else {
    if (TESTING) cout << "  mismatch: expected QUERIES or ID\n";
  }
  return success;
}

bool Parser::headPredicate() {
  bool success = false;
  if (peek() == ID) {
    if (TESTING) cout << "headPredicate check started...\n";
    success = matchID() && matchLeftParen() && matchID() && idList() && 
      matchRightParen();
  } else {
    if (TESTING) cout << "  mismatch: expected ID\n";
  }
  return success;
}

bool Parser::predicate() {
  bool success = false;
  if (peek() == ID) {
    if (TESTING) cout << "predicate check started...\n";
    success = matchID() && matchLeftParen() && parameter() && 
      parameterList() && matchRightParen();
  } else {
    if (TESTING) cout << "  mismatch: expected ID\n";
  }
  return success;
}

bool Parser::predicateList() {
  bool success = false;
  if (peek() == PERIOD) {
    success = true;
  } else if (peek() == COMMA) {
    if (TESTING) cout << "predicateList check started...\n";
    success = matchComma() && predicate() && predicateList();
  } else {
    if (TESTING) cout << "  mismatch: expected , or .\n";
  }
  return success;
}

bool Parser::parameter() {
  bool success = false;
  if (peek() == ID) {
    success = matchID();
  } else if (peek() == STRING) {
    success = matchString();
  } else if (peek() == LEFT_PAREN) {
    success = expression();
  } else {
    if (TESTING) cout << "  mismatch: expected ID or STRING or (\n";
  }
  return success;
}

bool Parser::parameterList() {
  bool success = false;
  if (peek() == RIGHT_PAREN) {
    success = true;
  } else if (peek() == COMMA) {
    if (TESTING) cout << "parameterList check started...\n";
    success = matchComma() && parameter() && parameterList();
  } else {
    if (TESTING) cout << "  mismatch: expected ) or ,\n";
  }
  return success;
}

bool Parser::expression() {
  bool success = false;
  if (peek() == LEFT_PAREN) {
    if (TESTING) cout << "expression check started...\n";
    success = matchLeftParen() && parameter() && checkOperator() &&
      parameter();
    if (success == false) {
      return success;
    }
    SectionName temp = section;
    section = EXPRESSION;
    success = matchRightParen();
    section = temp;
  } else {
    if (TESTING) cout << "  mismatch: expected (\n";
  }
  return success;
}

bool Parser::checkOperator() {
  bool success = false;
  if (peek() == ADD) {
    success = matchAdd();
  } else if (peek() == MULTIPLY) {
    success = matchMultiply();
  }
  return success;
}

bool Parser::query() {
  bool success = false;
  if (peek() == ID) {
    if (TESTING) cout << "query check started...\n";
    success = predicate() && matchQMark();
  }
  return success;
}

bool Parser::queryList() {
  bool success = false;
  if (peek() == END_OF_FILE) {
    success = true;
  } else if (peek() == ID) {
    if (TESTING) cout << "queryList check started...\n";
    success = query() && queryList();
  }
  return success;
}

bool Parser::stringList() {
  bool success = false;
  if (peek() == RIGHT_PAREN) {
    success = true;
  } else if (peek() == COMMA) {
    if (TESTING) cout << "stringList check started...\n";
    success = matchComma() && matchString() && stringList();
  }
  return success;
}

bool Parser::matchSchemes() {
  if (peek() == SCHEMES) {
    section = SCHEME;
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  SCHEMES matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected SCHEMES\n";
  return false;
}

bool Parser::matchFacts() {
  if (peek() == FACTS) {
    section = FACT;
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  FACTS matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected FACTS\n";
  return false;
}

bool Parser::matchRules() {
  if (peek() == RULES) {
    section = RULE_HEAD;
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  RULES matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected RULES\n";
  return false;
}

bool Parser::matchQueries() {
  if (peek() == QUERIES) {
    section = QUERY;
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  QUERIES matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected QUERIES\n";
  return false;
}

bool Parser::matchID() {
  if (peek() == ID) {
    if (TESTING) cout << "  ID matched: " << token_list[0].contents << "\n";
    parsed_tokens.push_back(token_list[0]);
    token_list.erase(token_list.begin());
    return true;
  }
  if (TESTING) cout << "  mismatch: expected ID\n";
  return false;
}

bool Parser::matchString() {
  if (peek() == STRING) {
    if (TESTING) cout << "  STRING matched: " << token_list[0].contents << "\n";
    parsed_tokens.push_back(token_list[0]);
    if (section == FACT) {
      program.domain.push_back(token_list[0].contents);
    }
    token_list.erase(token_list.begin());
    return true;
  }
  if (TESTING) cout << "  mismatch: expected STRING\n";
  return false;
}

bool Parser::matchLeftParen() {
  if (peek() == LEFT_PAREN) {
    if (section == RULE_LIST || section == QUERY) {
      nested_parenthesis++;
    }
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  ( matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected (\n";
  return false;
}

bool Parser::matchRightParen() {
  if (peek() == RIGHT_PAREN) {
    if (section == SCHEME) {
      Scheme new_scheme;
      new_scheme.id = parsed_tokens[0].contents;
      parsed_tokens.erase(parsed_tokens.begin());
      for (unsigned int i = 0; i < parsed_tokens.size(); i++) {
        new_scheme.id_list.push_back(parsed_tokens[i].contents);
      }
      parsed_tokens.clear();
      program.schemes.push_back(new_scheme);
      if (TESTING) {
        cout << "  adding new scheme: " << new_scheme.toString();
      }
    // } else if (nested_parenthesis > 1) {
    //   nested_parenthesis--;
    } else if (section == RULE_HEAD || section == RULE_LIST) {
      Predicate new_predicate;
      new_predicate.id = parsed_tokens[0].contents;
      parsed_tokens.erase(parsed_tokens.begin());
      for (unsigned int i = 0; i < parsed_tokens.size(); i++) {
        Parameter new_parameter(parsed_tokens[i].contents);
        new_predicate.parameter_list.push_back(new_parameter);
      }
      parsed_predicates.push_back(new_predicate);
      if (TESTING) {
        cout << "  adding new predicate: " << new_predicate.toString();
      }
      parsed_tokens.clear();
    }
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  ) matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected )\n";
  return false;
}

bool Parser::matchPeriod() {
  if (peek() == PERIOD) {
    if (section == FACT) {
      Fact new_fact;
      new_fact.id = parsed_tokens[0].contents;
      parsed_tokens.erase(parsed_tokens.begin());
      for (unsigned int i = 0; i < parsed_tokens.size(); i++) {
        new_fact.string_list.push_back(parsed_tokens[i].contents);
      }
      parsed_tokens.clear();
      program.facts.push_back(new_fact);
      if (TESTING) {
        cout << "  adding new fact: " << new_fact.toString();
      }
    } else {
      Rule new_rule;
      new_rule.head = parsed_predicates[0];
      parsed_predicates.erase(parsed_predicates.begin());
      for (unsigned int i = 0; i < parsed_predicates.size(); i++) {
        new_rule.predicate_list.push_back(parsed_predicates[i]);
      }
      parsed_predicates.clear();
      program.rules.push_back(new_rule);
      if (TESTING) {
        cout << "  adding new rule: " << new_rule.toString();
      }
    }
    token_list.erase(token_list.begin());
    if (section == RULE_LIST && peek() != QUERIES) {
      section = RULE_HEAD;
    }
    if (TESTING) cout << "  . matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected .\n";
  return false;
}

bool Parser::matchComma() {
  if (peek() == COMMA) {
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  , matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected ,\n";
  return false;
}

bool Parser::matchAdd() {
  if (peek() == ADD) {
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  + matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected +\n";
  return false;
}

bool Parser::matchMultiply() {
  if (peek() == MULTIPLY) {
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  * matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected *\n";
  return false;
}

bool Parser::matchColon() {
  if (peek() == COLON) {
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  : matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected :\n";
  return false;
}

bool Parser::matchColonDash() {
  if (peek() == COLON_DASH) {
    section = RULE_LIST;
    token_list.erase(token_list.begin());
    if (TESTING) cout << "  :- matched\n";
    return true;
  }
  if (TESTING) cout << "  mismatch: expected :-\n";
  return false;
}

bool Parser::matchQMark() {
  if (peek() == Q_MARK) {
    Predicate new_predicate;
    new_predicate.id = parsed_tokens[0].contents;
    parsed_tokens.erase(parsed_tokens.begin());
    for (unsigned int i = 0; i < parsed_tokens.size(); i++) {
      Parameter new_parameter(parsed_tokens[i].contents);
      new_predicate.parameter_list.push_back(new_parameter);
    }
    parsed_tokens.clear();
    Query new_query;
    new_query.predicate = new_predicate;
    token_list.erase(token_list.begin());
    program.queries.push_back(new_query);    
    if (TESTING) {
      cout << "  ? matched\n";
      cout << "  adding new query: " << new_predicate.toString() << "\n";;
    }
    return true;
  }
  if (TESTING) cout << "  mismatch: expected ?\n";
  return false;
}
