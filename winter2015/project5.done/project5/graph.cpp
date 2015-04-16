#include "graph.h"
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>

#define TESTING false

using namespace std;

void Graph::generateVertices(vector<Rule> rules) {
  // build vertices and adjacencies (super ugly)
  for (int i = 0; i < rules.size(); i++) {
    vector<int> adjacencies;
    for (int j = 0; j < rules[i].predicate_list.size(); j++) {
      for (int k = 0; k < rules.size(); k++) {
        if (rules[i].predicate_list[j].id == rules[k].head.id) {
          bool already_added = false;
          for (int l = 0; l < adjacencies.size(); l++) {
            if (adjacencies[l] == k) {
              already_added = true;
            }
          }
          if (!already_added) {
            adjacencies.push_back(k);
          }
        }
      }
    }
    vertices.push_back(adjacencies);
  }
}

void Graph::generateReverseVertices() {
  for (int i = 0; i < vertices.size(); i++) {
    vector<int> adjacencies;
    reverse_vertices.push_back(adjacencies);
  }
  for (int i = 0; i < vertices.size(); i++) {
    for (int j = 0; j < vertices[i].size(); j++) {
      reverse_vertices[vertices[i][j]].push_back(i);
    }
  }
}

string Graph::toString() {
  stringstream result;
  for (int i = 0; i < vertices.size(); i++) {
    result << "R" << i << ":";
    if (vertices[i].size() != 0) {
      for (int j = 0; j < vertices[i].size() - 1; j++) {
        result << "R" << vertices[i][j] << ",";
      }
      result << "R" << vertices[i].back() << "\n";
    } else {
      result << "\n";
    }
  }
  return result.str();
}

string Graph::reverseToString() {
  stringstream result;
  for (int i = 0; i < reverse_vertices.size(); i++) {
    result << "R" << i << ":";
    if (reverse_vertices[i].size() != 0) {
      for (int j = 0; j < reverse_vertices[i].size() - 1; j++) {
        result << "R" << reverse_vertices[i][j] << ",";
      }
      result << "R" << reverse_vertices[i].back() << "\n";
    } else {
      result << "\n";
    }
  }
  return result.str();
}

void Graph::DFS(vector<vector<int> > vertices, int number,
    stack<int> &vertex_stack, vector<int> &visited) {
  if (find(visited.begin(), visited.end(), number) != visited.end()) {
    return;
  }
  visited.push_back(number);
  for (int i = 0; i < vertices[number].size(); i++) {
    DFS(vertices, vertices[number][i], vertex_stack, visited);
  }
  vertex_stack.push(number);
}

// Maybe give it JUST set of vertices, a number, and a set for the SCC,
// and visited
void Graph::DFS(vector<vector<int> > vertices, int number,
    stack<int> &vertex_stack, vector<int> &visited, Component &SCC) {
  if (find(visited.begin(), visited.end(), number) != visited.end()) {
    return;
  }
  // Check to see if component goes to self at any point (so that identifying 
  // trivial components becomes a little easier)
  if (find(vertices[number].begin(), vertices[number].end(), number) !=
      vertices[number].end()) {
    SCC.goes_to_self = true;
  }
  visited.push_back(number);
  if (vertices[number].size() == 0) {
    SCC.rules.push_back(number);
    SCC.trivial = true;
    return;
  }
  SCC.rules.push_back(number);
  for (int i = 0; i < vertices[number].size(); i++) {
    DFS(vertices, vertices[number][i], vertex_stack, visited, SCC);
  }
}

// Remember for getting SCCs, run DFS on the original not the reverse

vector<Component> Graph::getSCCs() {
  // Generate reverse post order traversal in the form of a stack of numbers
  generateReverseVertices();
  vector<Component> SCCs;
  vector<int> visited;
  stack<int> reverse_post_order;
  for (int i = 0; i < reverse_vertices.size(); i++) {
    DFS(reverse_vertices, i, reverse_post_order, visited);
  }
  // perform DFS on original graph in the order of the RPOT to generate SCCs
  visited.clear();
  while (!reverse_post_order.empty()) {
    Component new_SCC;
    DFS(vertices, reverse_post_order.top(), reverse_post_order, visited, 
        new_SCC);
    for (int i = 0; i < new_SCC.rules.size(); i++) {
      if (TESTING) {
        cout << reverse_post_order.top() << " popped\n";
      }
      reverse_post_order.pop();
    }
    sort(new_SCC.rules.begin(), new_SCC.rules.end());
    // sometimes components that have only one rule but that do not go to
    // themselves don't get marked as trivial when they should be
    if (new_SCC.rules.size() == 1 && !new_SCC.goes_to_self) {
      new_SCC.trivial = true;
    } else if (new_SCC.rules.size() > 1) {
      new_SCC.trivial = false;
    }
    SCCs.push_back(new_SCC);
  }
  if (TESTING) {
    for(int i = 0; i < SCCs.size(); i++) {
      cout << SCCs[i].toString();
    }
  }
  return SCCs;
}
