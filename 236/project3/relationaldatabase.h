#ifndef RELATIONALDATABASE_H_
#define RELATIONALDATABASE_H_

#include "datalogprogram.h"
#include "relation.h"

class RelationalDatabase {
public:
  RelationalDatabase(DatalogProgram program);
  void answerQueries();
  std::vector<Relation> relations;
private:
  void generateRelations(DatalogProgram program);
  void removeDuplicateTuples(std::vector<std::vector<std::string> > &vec);
  int getSchemeIndex(Relation relation, std::string id);
  Relation getRelation(std::string id);
  Relation deleteColumn(Relation relation, int index);
  Relation select(Relation relation, int index, std::string token);
  Relation select(Relation relation, int index_one, int index_two);
  Relation rename(Relation relation, int index, std::string token);
  Relation project(Relation relation, std::vector<std::string> id_list);
  DatalogProgram program;
};

#endif // RELATIONALDATABASE_H_
