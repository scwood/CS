#ifndef FACT_H_
#define FACT_H_ 

#include <string>
#include <vector>

class Fact {
  public:
    Fact();
    ~Fact();
    std::string toString();
    std::string id;
    std::vector<std::string> string_list;
};

#endif // FACT_H_
