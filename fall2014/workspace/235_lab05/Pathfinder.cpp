#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Pathfinder.h"

using namespace std;

Pathfinder::Pathfinder() {
	srand (time(NULL));
	for (int z = 0 ; z < 5 ; z++) {
		for (int y = 0 ; y < 5 ; y++) {
			for (int x = 0 ; x < 5 ; x++) {
				maze[x][y][z] = "1";
			}
		}
	}
}

Pathfinder::~Pathfinder() {}

/////////////////////////////////////////////////////////////
// Extra helper functions
/////////////////////////////////////////////////////////////

void Pathfinder::addToSolution(int x, int y, int z) {
	stringstream convert;
	convert << "(" << x << ", " << y << ", " << z << ")";
	string coordinate = convert.str();
	solution.insert(solution.begin(), coordinate);
}

/////////////////////////////////////////////////////////////

string Pathfinder::getMaze() {
	string maze_container;
	for (int z = 0 ; z < 5 ; z++) {
		for (int y = 0 ; y < 5 ; y++) {
			for (int x = 0 ; x < 5 ; x++) {
				maze_container += maze[x][y][z];
				if (x == 4) {
					if (!(y == 4 && z == 4)) {
						maze_container += "\n";
					}
				}
				else maze_container += " ";
			}
		}
		if (z != 4) {
			maze_container += "\n";
		}
	}
	return maze_container;
}

void Pathfinder::createRandomMaze() {
	for (int z = 0 ; z < 5 ; z++) {
		for (int y = 0 ; y < 5 ; y++) {
			for (int x = 0 ; x < 5 ; x++) {
				int cell = rand() % 2;
				if (cell == 0) {
					maze[x][y][z] = "0";
				}
				else maze[x][y][z] = "1";
			}
		}
	}
	maze[0][0][0] = "1";
	maze[4][4][4] = "1";
}

bool Pathfinder::importMaze(string file_name) {
	fstream count_test(file_name.c_str());
	fstream maze_copy(file_name.c_str());
	string test;
	int count = 0;
	while (count_test >> test) {
		if (test != "0" && test != "1") {
			return false;
		}
		if (count == 0 && test != "1") {
			return false;
		}
		if (count == 124 && test != "1") {
			return false;
		}
		count ++;
	}
	if (count != 125) {
		return false;
	}
	for (int z = 0 ; z < 5 ; z++) {
		for (int y = 0 ; y < 5 ; y++) {
			for (int x = 0 ; x < 5 ; x++) {
				maze_copy >> test;
				maze[x][y][z] = test;
			}
		}
	}
	return true;
}

vector<string> Pathfinder::solveMaze() {
	solution.clear();
	recursiveSolve(0, 0, 0);
	for (int z = 0 ; z < 5 ; z++) {
		for (int y = 0 ; y < 5 ; y++) {
			for (int x = 0 ; x < 5 ; x++) {
				if (maze[x][y][z] == "2") {
					maze[x][y][z] = "1";
				}
			}
		}
	}
	return solution;
}

bool Pathfinder::recursiveSolve(int x, int y, int z) {
	if (x < 0 || y < 0 || z < 0 || x > 4 || y > 4 || z > 4) {
		return false;
	}
	if (maze[x][y][z] != "1") {
		return false;
	}
	if (x == 4 && y == 4 && z == 4) {
		addToSolution(x, y, z);
		return true;
	}
	maze[x][y][z] = "2";
	if (recursiveSolve(x + 1, y, z)) {
		addToSolution(x, y, z);
		return true;
	}
	if (recursiveSolve(x - 1, y, z)) {
		addToSolution(x, y, z);
		return true;
	}
	if (recursiveSolve(x, y + 1, z)) {
		addToSolution(x, y, z);
		return true;
	}
	if (recursiveSolve(x, y - 1, z)) {
		addToSolution(x, y, z);
		return true;
	}
	if (recursiveSolve(x, y, z + 1)) {
		addToSolution(x, y, z);
		return true;
	}
	if (recursiveSolve(x, y, z - 1)) {
		addToSolution(x, y, z);
		return true;
	}
	return false;
}
