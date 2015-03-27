#include "scheme.h"
#include <sstream>

using namespace std;

Scheme::Scheme() {
  id = "";
}

Scheme::~Scheme() {}

string Scheme::toString() {
  stringstream result;
  result << id << "(";
  for (int i = 0; i < id_list.size() - 1; i++) {
    result << id_list[i] << ",";
  }
  result << id_list.back() << ")\n";
	return result.str();
}
