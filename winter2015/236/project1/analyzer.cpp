#include "analyzer.h"

Analyzer::Analyzer() {
  current_token = UNDEFINED;
  character_count = 0;
  line_number = 1;
  extra_carriage_returns = 0;
  number_of_tokens = 1;
}

Analyzer::~Analyzer() {}

void Analyzer::printTokens(string file_name) {
  // open file, check that it opens
  ifstream file(file_name.c_str());
  if (!file) {
    cout << "Bad input file.\n";
    return;
  }
  // read file into string preserving whitespace
  stringstream buffer;
  buffer << file.rdbuf();
  string file_string = buffer.str();
  // put string through DFAs
  while (file_string.size() > 0) {
    checkComma(file_string);
    checkPeriod(file_string);
    checkQuestionMark(file_string);
    checkLeftParenthesis(file_string);
    checkRightParenthesis(file_string);
    checkMultiply(file_string);
    checkAdd(file_string);
    checkColon(file_string);
    checkComment(file_string);
    checkString(file_string);
    checkAlphas(file_string);
    checkWhitespace(file_string);
    if (character_count == 0) {
      character_count = 1;
      current_token = UNDEFINED;
    }
    if (current_token != WHITESPACE) {
      cout << "(" << enumToString(current_token) << ",\""
       << file_string.substr(0, character_count)
        << "\"," << line_number << ")\n";
      number_of_tokens++;
    }
    // consume token
    file_string.erase(0, character_count);
    // fix line number
    line_number += extra_carriage_returns;
    // reset values
    extra_carriage_returns = 0;
    character_count = 0;
    current_token = UNDEFINED;
  }
  cout << "(EOF,\"\"," << line_number << ")\n";
  cout << "Total Tokens = " << number_of_tokens << "\n";
}

void Analyzer::checkComma(string input) {
  unsigned int i = 0;
  // comma DFA
  if (input[i] == ',') {
    character_count = 1;
    current_token = COMMA;
  } 
}

void Analyzer::checkPeriod(string input) {
  // period DFA
  unsigned int i = 0;
  if (input[i] == '.') {
    character_count = 1;
    current_token = PERIOD;
  } 
}

void Analyzer::checkQuestionMark(string input) {
  // question mark DFA
  unsigned int i = 0;
  if (input[i] == '?') {
    character_count = 1;
    current_token = Q_MARK;
  } 
}

void Analyzer::checkLeftParenthesis(string input) {
  // left parenthesis DFA
  unsigned int i = 0;
  if (input[i] == '(') {
    character_count = 1;
    current_token = LEFT_PAREN;
  } 
}

void Analyzer::checkRightParenthesis(string input) {
  // right parenthesis DFA
  unsigned int i = 0;
  if (input[i] == ')') {
    character_count = 1;
    current_token = RIGHT_PAREN;
  } 
}

void Analyzer::checkMultiply(string input) {
  // multiply DFA
  unsigned int i = 0;
  if (input[i] == '*') {
    character_count = 1;
    current_token = MULTIPLY;
  } 
}

void Analyzer::checkAdd(string input) {
  // add DFA
  unsigned int i = 0;
  if (input[i] == '+') {
    character_count = 1;
    current_token = ADD;
  } 
}

void Analyzer::checkColon(string input) {
  // colon DFA
  unsigned int i = 0;
  if (input[i] == ':') {
    i++;
    if (input[i] == '-') {
      character_count = 2;
      current_token = COLON_DASH;
    } else {
      character_count = 1;
      current_token = COLON;
    }
    i = 0;
  } 
}

void Analyzer::checkComment(string input) {
  // comment DFA
  unsigned int i = 0;
  if (input[i] == '#') {
    i++;
    character_count = 1;
    current_token = COMMENT;
    if (input[i] != '|' && input[i] != '\n') {
      // single line comment
      i++;
      character_count++;
      while (input[i] != '\n') {
        i++;
        character_count++;
      }
    } else if (input[i] == '|') {
      // block comment
      i++;
      character_count++;
      bool block_terminated = false;
      while (!block_terminated) {
        while (i < (input.size() - 1) && input[i] != '|') {
          if (input[i] == '\n') {
            extra_carriage_returns++;
          }
          i++;
          character_count++;
        }
        if (i == (input.size() - 1)) {
          block_terminated = true;
          current_token = UNDEFINED;
          character_count++;
          extra_carriage_returns++;
        } else if (input[i] == '|') {
          i++;
          character_count++;
          if (i < (input.size() - 1) && input[i] == '#') {
            character_count++;
            block_terminated = true;
          }
        }
      }
    }
  }
}

void Analyzer::checkString(string input) {
  // string DFA
  unsigned int i = 0;
  if (input[i] == '\'') {
    i++;
    character_count = 1;
    bool string_terminated = false;
    while (!string_terminated) {
      while (i < (input.size() - 1) && input[i] != '\'') {
        if (input[i] == '\n') {
          extra_carriage_returns++;
        }
        i++;
        character_count++;
      }
      if (i == input.size() - 1 && input[i] == '\'') {
        string_terminated = true;
        character_count++;
        current_token = STRING;
      } else if (input[i] == '\'') {
        i++;
        character_count++;
        if (input[i] != '\'') {
          string_terminated = true;
          current_token = STRING;
        } else {
          i++;
          character_count++;
        }
      } else if (i == input.size() - 1) {
        character_count++;
        extra_carriage_returns++;
        string_terminated = true;
        current_token = UNDEFINED;
      }
    }
  }
}

void Analyzer::checkAlphas(string input) {
  // keyword/ID DFA
  unsigned int i = 0;
  if (isalpha(input[i])) {
    i++;
    character_count++;
    while (isalpha(input[i]) || isdigit(input[i])) {
      i++;
      character_count++;
    }
    string current_string = input.substr(0, character_count);
    if (current_string == "Schemes") {
      current_token = SCHEMES;
    } else if (current_string == "Rules") {
      current_token = RULES;
    } else if (current_string == "Facts") {
      current_token = FACTS;
    } else if (current_string == "Queries") {
      current_token = QUERIES;
    } else {
      current_token = ID;
    }
  }
}

void Analyzer::checkWhitespace(string input) {
  // whitespace DFA
  unsigned int i = 0;
  if (isspace(input[i])) {
    current_token = WHITESPACE;
    character_count = 1;
    if (input[i] == '\n') {
      line_number++;
    }
  }
}

string Analyzer::enumToString(token tokenType) {
  switch(tokenType) {
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
