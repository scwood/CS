/*
 * Pathfinder.h
 *
 *  Created on: Oct 23, 2014
 *      Author: Spencer
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include "PathfinderInterface.h"

using namespace std;

class Pathfinder : public PathfinderInterface {
private:
	string maze[5][5][5];
	vector<string> solution;
public:
	Pathfinder();
	~Pathfinder();
	void addToSolution(int x, int y, int z);
	string getMaze();
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
	bool recursiveSolve(int x, int y, int z);
};

#endif /* PATHFINDER_H_ */
