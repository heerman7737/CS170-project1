#include <iostream>
#include <vector>
#include "puzzle.h"
using namespace std;
bool goal(vector<vector<int>> a) {
    bool result = true;
    vector<vector<int>> pg{ {1,2,3},{4,5,6},{7,8,0} };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != pg[i][j]) {
                result = false;
                break;
            }
        }
    }
    return result;
}
Puzzle puzzle;
int main()
{

    vector<vector<int>> tile;
    int temp;
    cout << "Welcome to my 8-puzzle solver.\n";
    cout << "Enter your puzzle in the following format: 0 1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < 3; i++) {
        tile.push_back(vector<int>());
        for (int j = 0; j < 3; j++) {
            cin >> temp;
            tile[i].push_back(temp);
        }
    }
    puzzle.setPuzzle(tile);
    vector<char> all_move = puzzle.move();
    puzzle.printPuzzle();
    for (int i = 0; i < all_move.size(); i++) {
        cout << all_move[i] << " ";
    }
    return 0;
}
