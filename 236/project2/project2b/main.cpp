#include "analyzer.h"
#include "parser.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argv[1] == NULL) {
    cout << "No input file\n";
    return 0;
  }
  string file_name = argv[1];
  Analyzer analyzer;
  Parser parser;
  vector<Tokens> token_list = analyzer.getParsableTokens(file_name);
  parser.parseTokens(token_list);
  return 0;
}
