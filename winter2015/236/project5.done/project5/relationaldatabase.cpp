#include "relationaldatabase.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include "datalogprogram.h"
#include "graph.h"

#define TESTING false

using namespace std;

RelationalDatabase::RelationalDatabase(DatalogProgram program) {
  this->program = program;
  database_size = 0;
  generateRelations(program);
  updateDatabaseSize();
}

void RelationalDatabase::updateDatabaseSize() {
  database_size = 0;
  for (int i = 0; i < relations.size(); i++) {
    database_size += relations[i].tuples.size();
  } 
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

void RelationalDatabase::evaluateRulesWithGraph() {
  Graph dependency_graph;
  dependency_graph.generateVertices(program.rules);
  cout << "Dependency Graph\n";
  cout << dependency_graph.toString();
  vector<Component> SCCs = dependency_graph.getSCCs();
  cout << "\nRule Evaluation\n";
  for (int i = 0; i < SCCs.size(); i++) {
    int passes = 0;
    if (SCCs[i].trivial) {
      passes++;
      evaluateRule(SCCs[i].rules[0]);
    } else {
      bool updating = true;
      while (updating) { 
        passes++;
        for (int j = 0; j < SCCs[i].rules.size(); j++) {
          evaluateRule(SCCs[i].rules[j]);
        }
        int old_database_size = database_size;
        updateDatabaseSize();
        if (database_size == old_database_size) {
          updating = false;
        }
      }
    }
    cout << passes << " passes: " << SCCs[i].toString();
  }
  cout << "\nQuery Evaluation\n";
}

void RelationalDatabase::evaluateRule(int rule){
  vector<Relation> intermediate_solutions;
  intermediate_solutions =
    evaluatePredicates(program.rules[rule]);
  Relation result = intermediate_solutions[0];
  if (intermediate_solutions.size() > 1) {
    for (int j = 1; j < intermediate_solutions.size(); j++) {
      result = naturalJoin(result, intermediate_solutions[j]);
    }
  }
  vector<string> id_list;
  for (int j = 0; 
      j < program.rules[rule].head.parameter_list.size(); 
      j++) {
    string id =
      program.rules[rule].head.parameter_list[j].contents;
    id_list.push_back(id);
  }
  result = project(result, id_list);
  result.id = program.rules[rule].head.id;
  unionWithDatabase(result);
}

void RelationalDatabase::evaluateRules() {
  int passes = 0;
  // go until rules aren't generating anymore facts
  int i = 0;
  bool updating = true;
  while(updating) {
    passes++;
    for (int i = 0; i < program.rules.size(); i++) {
      vector<Relation> intermediate_solutions;
      // (1) evaluate predicates from the rule
      intermediate_solutions = evaluatePredicates(program.rules[i]);
      // (2) natural join results from predicates
      Relation result = intermediate_solutions[0];
      if (intermediate_solutions.size() > 1) {
        for (int j = 1; j < intermediate_solutions.size(); j++) {
          result = naturalJoin(result, intermediate_solutions[j]);
        }
      }
      // (3) project result onto head predicate
      vector<string> id_list;
      for (int j = 0; j < program.rules[i].head.parameter_list.size(); j++) {
        string id = program.rules[i].head.parameter_list[j].contents;
        id_list.push_back(id);
      }
      result = project(result, id_list);
      result.id = program.rules[i].head.id;
      if (TESTING) {
        cout << "Final solution\n";
        cout << result.toString();
        cout << "------------------------------------------------------\n";
      }
      // (4) union reult with original relation
      unionWithDatabase(result);
    }
    int old_database_size = database_size;
    updateDatabaseSize();
    if (database_size == old_database_size) {
      updating = false;
    }
  }
  cout << "Schemes populated after ";
  cout << passes;
  cout << " passes through the Rules.\n";
}

vector<Relation> RelationalDatabase::evaluatePredicates(Rule rule) {
  vector<Relation> solutions;
  Predicate predicate;
  vector<Parameter> parameters;
  Relation relation;
  vector<string> id_list;
  bool needs_project = false;
  // Evaluate each predicate
  for (int i = 0; i < rule.predicate_list.size(); i++) {
    predicate = rule.predicate_list[i];
    parameters = predicate.parameter_list;
    relation = getRelation(predicate.id);
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
    relation.id = rule.predicate_list[i].id;
    if (TESTING) {
      cout << "Intermediate solution:\n" << relation.toString();
    }
    solutions.push_back(relation);
    id_list.clear();
    needs_project = false;
  }
  return solutions;
}

void RelationalDatabase::unionWithDatabase(Relation relation) {
  int index = -1;
  for (int i = 0; i < relations.size(); i++) {
    if (relation.id == relations[i].id) {
      index = i;
      break;
    } 
  }
  if (TESTING && index == -1) {
    cout << "Rule id not found in database\n";
    return;
  } 
  relations[index].tuples.insert(relations[index].tuples.begin(),
    relation.tuples.begin(), relation.tuples.end());
  removeDuplicateTuples(relations[index].tuples);
}

Relation RelationalDatabase::naturalJoin(Relation r1, Relation r2) {
  Relation result;
  // combine schemes
  result.scheme = r1.scheme;
  result.scheme.insert(result.scheme.end(), r2.scheme.begin(),
      r2.scheme.end());
  // combine tuples
  for (int i = 0; i < r1.tuples.size(); i++) {
    for (int j = 0; j < r2.tuples.size(); j++) {
      if (joinable(r1.tuples[i], r2.tuples[j], r1.scheme, r2.scheme)) {
        vector<string> new_tuple = join(r1.tuples[i], r2.tuples[j]);
        result.tuples.push_back(new_tuple);
      }
    }
  }
  return result;
}

bool RelationalDatabase::joinable(vector<string> t1, vector<string> t2,
    vector<string> s1, vector<string> s2) {
  for (int i = 0; i < s1.size(); i++) {
    for (int j = 0; j < s2.size(); j++) {
      if (s1[i] == s2[j] && t1[i] != t2[j]) {
        return false;
      }
    }
  }
  return true;
}
vector<string> RelationalDatabase::join(vector<string> t1, vector<string> t2) {
  vector<string> new_tuple = t1;
  new_tuple.insert(new_tuple.end(), t2.begin(), t2.end());
  return new_tuple;
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
  Relation new_relation;
  if (relation.tuples.size() == 0) {
    return new_relation;
  }
  vector<string> schemes = relation.scheme;
  for (int i = 0; i < id_list.size(); i++) {
    // grab position of id from id_list
    int index = find(schemes.begin(), schemes.end(), id_list[i]) -
      schemes.begin();
    new_relation.scheme.push_back(schemes[index]);
    // create tuples on the first time
    if (i == 0) {
      for (int j = 0; j < relation.tuples.size(); j++) {
        vector<string> new_tuple;
        new_tuple.push_back(relation.tuples[j][index]);
        new_relation.tuples.push_back(new_tuple);
      }
    // on subsequent times add to existing tuples
    } else {
      for (int j = 0; j < relation.tuples.size(); j++) {
        new_relation.tuples[j].push_back(relation.tuples[j][index]);
      }
    }
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
