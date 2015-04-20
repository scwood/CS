#ifndef GRAPH_H_
#define GRAPH_H_

#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include "component.h"
#include "rule.h"

class Graph {
  public:
    void generateVertices(std::vector<Rule> rules);
    void generateReverseVertices();
    std::vector<Component> getSCCs();
    std::string toString();
    std::string reverseToString();
  private:
    void DFS(std::vector<std::vector<int> > vertices, int number,
        std::stack<int> &vertex_stack, std::vector<int>& visited);
    void DFS(std::vector<std::vector<int> > vertices, int number,
        std::stack<int> &vertex_stack, std::vector<int>& visited,
        Component &SCC);
    std::vector<std::vector<int> > vertices;
    std::vector<std::vector<int> > reverse_vertices;
};

#endif // GRAPH_H_
