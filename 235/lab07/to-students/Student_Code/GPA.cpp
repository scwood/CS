#include "GPA.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Student.h"

GPA::GPA() {}

GPA::~GPA() {}

map<unsigned long long int, StudentInterface*> GPA::getMap() {
	return studentMap;
}

set<StudentInterface*, Comparator> GPA::getSet() {
	return studentSet;
}

bool GPA::importStudents(string mapFileName, string setFileName) {
	ifstream map_file_check;
	ifstream set_file_check;
	map_file_check.open(mapFileName.c_str());
	set_file_check.open(setFileName.c_str());
	if (!map_file_check || !set_file_check) {
		cout << "Invalid file names.\n";
		return false;
	}
	// check for valid number of entries in map file
	string line = "";
	while (getline(map_file_check, line)) {
		stringstream convert(line);
		unsigned long long int ID_temp;
		convert >> ID_temp;
		if (convert.fail()) {
			cout << "Invalid map file.\n";
			return false;
		}
		for (int i = 0; i < 2; i++) {
			getline(map_file_check, line);
			if (map_file_check.eof()) {
				cout << "Invalid map file\n";
				return false;
			}
		}
	}
	// check for valid number of entries in set file
	while (getline(set_file_check, line)) {
		stringstream convert(line);
		unsigned long long int ID_temp;
		convert >> ID_temp;
		if (convert.fail()) {
			cout << "Invalid set file.\n";
			return false;
	}
		for (int i = 0; i < 2; i++) {
			getline(set_file_check, line);
			if (set_file_check.eof()) {
				cout << "Invalid set file\n";
				return false;
			}
		}
	}
	// everything looks good, files ready to import
	ifstream map_file;
	map_file.open(mapFileName.c_str());
	while (!map_file.eof()) {
		getline(map_file, line);
		Student* newStudent = new Student();
		stringstream convert(line);
		unsigned long long int ID_temp;
		convert >> ID_temp;
		newStudent->ID = ID_temp;
		getline(map_file, line);
		newStudent->name = line;
		getline(map_file, line);
		newStudent->address = line;
		getline(map_file, line);
		newStudent->phone_number = line;
		studentMap.insert(pair<unsigned long long int, StudentInterface*>
			(ID_temp, newStudent));
		cout << "Student with ID: " << ID_temp << " added to the map.\n";
	}
	ifstream set_file;
	set_file.open(setFileName.c_str());
	while (!set_file.eof()) {
		getline(set_file, line);
		Student* newStudent = new Student();
		stringstream convert(line);
		unsigned long long int ID_temp;
		convert >> ID_temp;
		newStudent->ID = ID_temp;
		getline(set_file, line);
		newStudent->name = line;
		getline(set_file, line);
		newStudent->address = line;
		getline(set_file, line);
		newStudent->phone_number = line;
		// is this right
		studentSet.insert(newStudent);
		// -------------
		cout << "Student with ID: " << ID_temp << " added to the set.\n";
	}
	return true;
}

bool GPA::importGrades(string fileName) {
	return false;
}

string GPA::querySet(string fileName) {
	return "";
}

string GPA::queryMap(string fileName) { 
	return "";
}

void GPA::clear() {
}