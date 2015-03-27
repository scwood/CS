# Map

key | value
-------------
2   | davis
3   | aaron
4   | etc

keys and values can be any data type

map<unsinged long long int, SI*> myMap

# Set

sets are ordered

set<StudentInterface*, comparator>

comparator orders the stuff by name in the SI*

# Import Students

importStudents(mapFile, setFile);

myMap.insert(pair<ID, SI pointer> (ID, SI pointer))

# Import grades

importGrades(fileName)

Student ID
Class name
Grade

How to calculate gpa
Overall GPA: Every time add grade, just add it together (i.e. 18.7)
Classes: Add one every class (i.e. 5)
GPA: Overall/classes

,,,
myMap.find(3) != myMap.end()

map<ULLI, SI ptr>::iterator it;

it->second is the value

SI ptr temp = it->second
temp.setGPA(A);

set <SI*, comparator>::iter it;

for (it = mySet.begin(); it != mySet.end(); ++it) {
	SI ptr temp = *it;
	if (temp->getID == ID) {
		temp->setGPA(grade);
	}
}
,,,

# Clear
