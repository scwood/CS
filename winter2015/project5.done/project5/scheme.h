#ifndef SCHEME_H_
#define SCHEME_H_

#include <string>
#include <vector>

class Scheme {
  public:
    Scheme();
    ~Scheme();
    std::string toString();
    std::string id;
    std::vector<std::string> id_list;
};

#endif // SCHEMES_H_
