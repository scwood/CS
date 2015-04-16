#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>
#include <vector>

class Component {
  public:
    Component();
    std::string toString();
    std::vector<int> rules;
    bool trivial;
    bool goes_to_self;
}; 

#endif // COMPONENT_H_
