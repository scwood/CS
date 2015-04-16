#include "analyzer.h"
#include "parser.h"
#include "relationaldatabase.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argv[1] == NULL) {
    cout << "No input file\n";
    return 0;
  }
  string file_name = argv[1];
  Analyzer analyzer;
  vector<Tokens> token_list = analyzer.getParsableTokens(file_name);
  Parser parser;
  DatalogProgram program = parser.getProgram(token_list);
  RelationalDatabase database(program);
  database.evaluateRulesWithGraph();
  database.answerQueries();
  return 0;
}
