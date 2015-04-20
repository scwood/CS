#include "relationaldatabase.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include "datalogprogram.h"

using namespace std;

RelationalDatabase::RelationalDatabase(DatalogProgram program) {
  this->program = program;
  generateRelations(program);
}

void RelationalDatabase::generateRelations(DatalogProgram program) {
  // Build relations from schemes
  for (int i = 0; i < program.schemes.size(); i++) {
    Relation new_relation;
    new_relation.id = program.schemes[i].id;
    new_relation.scheme = program.schemes[i].id_list;
    // Generate table of tuples from facts for each scheme
    for (int i = 0; i < program.facts.size(); i++) {
      if (program.facts[i].id == new_relation.id) {
        new_relation.tuples.push_back(program.facts[i].string_list);
      }
    }
    removeDuplicateTuples(new_relation.tuples);
    relations.push_back(new_relation);
  }
}

void RelationalDatabase::removeDuplicateTuples(vector<vector<string> > &vec) {
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

void RelationalDatabase::answerQueries() {
  Query query;
  vector<Parameter> parameters;
  Relation relation;
  vector<string> id_list;
  bool needs_project = false;
  // Evaluate each query
  for (int i = 0; i < program.queries.size(); i++) {
    stringstream result;
    query = program.queries[i];
    parameters = query.predicate.parameter_list;
    relation = getRelation(query.predicate.id);
    // Evaluate each parameter using relational algebra
    for (int j = 0; j < parameters.size(); j++) {
      // If param is string select
      if (parameters[j].is_string) {
        relation = select(relation, j, parameters[j].contents);
      // If param is id and  has been seen already
      } else if (
          find(id_list.begin(), id_list.end(), parameters[j].contents)
          != id_list.end()) {
        relation = select(
            relation, j, getSchemeIndex(relation, parameters[j].contents));
      // If param is id and hasn't been seen, rename and push onto id_list
      } else {
        id_list.push_back(parameters[j].contents);
        relation = rename(relation, j, parameters[j].contents);
        needs_project = true;
      }
    }
    if (needs_project) {
      relation = project(relation, id_list);
    }
    // Build string object to cout
    result << query.toStringNoNewLine();
    vector<vector<string> > answers = relation.tuples;
    if (answers.size() == 0) {
      result << " No\n";
    } else if (id_list.size() == 0) {
      result << " Yes(1)\n";
    } else {
      result << " Yes(" << relation.tuples.size() << ")\n";
      for (int i = 0; i < relation.tuples.size(); i++) {
        result << "  ";
        for (int j = 0; j < relation.tuples[i].size() - 1; j++) {
          result << relation.scheme[j] << "=" << relation.tuples[i][j]
            << ", ";
        }
        result << relation.scheme[relation.scheme.size() - 1] << "=" 
          <<relation.tuples[i][relation.tuples[i].size() - 1] << "\n";
      }
    }
    id_list.clear();
    needs_project = false;
    cout << result.str();
  }
}

Relation RelationalDatabase::getRelation(string id) {
  Relation matched_relation;
  for (int i = 0; i < relations.size(); i++) {
    if (relations[i].id == id) {
      matched_relation = relations[i];
    }
  }
  return matched_relation;
}

// Regular string constant select
Relation RelationalDatabase::select(
    Relation relation, int index, string token) {
  Relation new_relation = relation;
  new_relation.tuples.clear();
  for (int i = 0; i < relation.tuples.size(); i++) {
    if (relation.tuples[i][index] == token) {
      new_relation.tuples.push_back(relation.tuples[i]);
    }
  }
  return new_relation;
}

// Special case select
Relation RelationalDatabase::select(
    Relation relation, int index_one, int index_two) {
  Relation new_relation = relation;
  new_relation.tuples.clear();
  for (int i = 0; i < relation.tuples.size(); i++) {
    if (relation.tuples[i][index_one] == relation.tuples[i][index_two]) {
      new_relation.tuples.push_back(relation.tuples[i]);
    }
  } 
  return new_relation;
}

Relation RelationalDatabase::rename(
    Relation relation, int index, string token) {
  Relation new_relation = relation;
  new_relation.scheme[index] = token;
  return new_relation;
}

Relation RelationalDatabase::project(
    Relation relation, vector<string> id_list) {
  Relation new_relation = relation;
  int index = 0;
  bool finished = false;
  bool scheme_found = false;
  while(!finished) {
    for (int j = 0; j < id_list.size(); j++) {
      if (new_relation.scheme[index] == id_list[j]) {
        scheme_found = true;
      }
    }
    if (!scheme_found) {
      new_relation = deleteColumn(new_relation, index);
    } else {
      index++;
    }
    if (index == new_relation.scheme.size()) {
      finished = true;
    }
    scheme_found = false;
  }
  return new_relation;
}

Relation RelationalDatabase::deleteColumn(Relation relation, int index) {
  Relation new_relation = relation;
  new_relation.scheme.erase(new_relation.scheme.begin() + index);
  for (int i = 0; i < new_relation.tuples.size(); i++) {
    new_relation.tuples[i].erase(new_relation.tuples[i].begin() + index);
  }
  return new_relation;
}

int RelationalDatabase::getSchemeIndex(Relation relation, string id) {
  int index = 0;
  for (int i = 0; i < relation.scheme.size(); i++) {
    if (relation.scheme[i] == id) {
      index = i;
    }
  }
  return index;
}
