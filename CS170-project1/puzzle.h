#pragma once
#ifndef PUZZLE_H
#define PUZZLE_H
#include <string>
#include <vector>

using namespace std;

class Puzzle {

public:
	vector<int> state;
	int cost;
	int h_cost;
	int g_cost;
	Puzzle* parent;
	Puzzle* up;
	Puzzle* down;
	Puzzle* left;
	Puzzle* right;
public:
	Puzzle();
	Puzzle(vector<int>);
	Puzzle(Puzzle*);
	void setPuzzle(vector<int> tile);
	void printPuzzle();
	int findEmpty();
	bool compare(Puzzle* p1, Puzzle* p2);
	Puzzle* move_up();
	Puzzle* move_down();
	Puzzle* move_left();
	Puzzle* move_right();
};


#endif // !1