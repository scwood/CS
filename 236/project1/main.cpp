#include "analyzer.h"

int main(int argc, char* argv[]) {
  if (argv[1] == NULL) {
    cout << "No input file\n";
    return 0;
  }
  Analyzer analyzer;
  analyzer.printTokens(argv[1]);
  return 0;
}
