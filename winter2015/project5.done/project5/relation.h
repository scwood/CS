#ifndef RELATION_H_
#define RELATION_H_

#include <string>
#include <vector>

class Relation {
  public:
    std::string toString();
    std::string id;
    std::vector<std::string> scheme;
    std::vector<std::vector<std::string> > tuples;
};

#endif // RELATION_H_
