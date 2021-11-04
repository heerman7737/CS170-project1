#include "puzzle.h"
#include <vector>
#include <iostream>
using namespace std;
Puzzle::Puzzle() {

    cost = 0;
    parent = NULL;
}

void Puzzle::setPuzzle(vector<vector<int>> tile) {
    for (int i = 0; i < 3; i++) {
        state.push_back(vector<int>());
        for (int j = 0; j < 3; j++) {
            state[i].push_back(tile[i][j]);
        }
    }
}
void Puzzle::printPuzzle() {
    vector<vector<int>> result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << state[i][j] << " ";
        }
    }
}

vector<char> Puzzle::move() {
    vector<char> result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (state[i][j] == 0) {
                if (i == 0 && j == 0) result = { 'l','u' };
                if (i == 0 && j == 1) result = { 'r','l','u' };
                if (i == 0 && j == 2) result = { 'r','u' };
                if (i == 1 && j == 0) result = { 'd','u','l' };
                if (i == 1 && j == 1) result = { 'd','u','l','u' };
                if (i == 1 && j == 2) result = { 'd','u','r' };
                if (i == 2 && j == 0) result = { 'd','l' };
                if (i == 2 && j == 1) result = { 'd','r','l' };
                if (i == 2 && j == 2) result = { 'd','r' };
            }
        }
    }
    return result;
}