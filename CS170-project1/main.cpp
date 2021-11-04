#include <iostream>
#include <vector>
#include "puzzle.h"
using namespace std;
int main()
{
    

    vector<int> tile;
    int temp;
    cout << "Welcome to my 8-puzzle solver.\n";
    cout << "Enter your puzzle in the following format: 0 1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < 9; i++) {
        cin >> temp;
        tile.push_back(temp);
    }
    //for (int i = 0; i < 9; i++) {
    //    cout << tile[i]<<" ";
    //}
    int choice;
    cout << "Choose your algorithm:\n";
    cout << "Enter 1. Uniform Cost Search\n";
    cout << "Enter 2. A* with Misplaced Tile Heuristics\n";
    cout << "Enter 3. A* with Manhattan Distance Heuristics\n";
    cin >> choice;
    //cout << choice;
    return 0;
}

