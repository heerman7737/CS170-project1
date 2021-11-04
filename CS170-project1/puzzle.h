#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
#include <string>
#include <vector>

using namespace std;

class Puzzle {
	vector<vector<int>> state;
	int cost;
	Puzzle* parent;
public:
	Puzzle();
	void setPuzzle(vector<vector<int>> tile);
	void printPuzzle();
	vector<char> move();

};


#endif // !1