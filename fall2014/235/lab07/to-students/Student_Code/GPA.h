#ifndef GPA_H_
#define GPA_H_

#include "GPAInterface.h"

class GPA : public GPAInterface {
public:
	GPA();
	~GPA();

	// methods
	map<unsigned long long int, StudentInterface*> getMap();
	set<StudentInterface*, Comparator> getSet();
	bool importStudents(string mapFileName, string setFileName);
	bool importGrades(string fileName);
	string querySet(string fileName);
	string queryMap(string fileName);
	void clear();

	// data members
	map<unsigned long long int, StudentInterface*> studentMap;
	set<StudentInterface*, Comparator> studentSet;
};

#endif // GPA_H_