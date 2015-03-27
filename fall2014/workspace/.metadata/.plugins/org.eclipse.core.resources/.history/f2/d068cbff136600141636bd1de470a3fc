#include <iostream>
#include "Team.h"
using namespace std;

int main() {
	Team test;
	test.addHeadPerson("p1", 1, 1);
	test.addHeadPerson("p2", 1, 1);
	test.remove("p2");
	test.printTeam();
	cout << "------" << endl;
	test.addHeadPerson("p3", 1, 1);
	test.addHeadPerson("p4", 1, 1);
	test.remove("p3");
	test.printTeam();
	test.addHeadPerson("p5", 1, 1);
	test.addHeadPerson("p6", 1, 1);
	test.addHeadPerson("p7", 1, 1);
	test.addHeadPerson("p8", 1, 1);
	test.addHeadPerson("p9", 1, 1);
	test.addHeadPerson("p10", 1, 1);
	test.addHeadPerson("p11", 1, 1);
	test.printTeam();
	cout << "-----" << endl;
	test.remove("p6");
	test.remove("p11");
	test.remove("p1");
	test.printTeam();
	test.insertAfter("p4", "p12", 1, 1);
	test.insertAfter("p8", "p13", 1, 1);
	test.insertAfter("p10", "p14", 1, 1);
	test.printTeam();
	cout << "-----" << endl;
	test.insertBetween("p4", "p15", 1, 1);
	test.insertBetween("p5", "p16", 1, 1);
	test.insertBetween("p14", "p17", 1, 1);
	test.printTeam();
	cout << "-------------" << endl;
	test.shuffleTeam();
	test.printTeam();
	test.shuffleTeam();
	test.printTeam();
	test.shuffleTeam();
	test.printTeam();
	return 0;
}