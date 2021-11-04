#include <iostream>
#include <vector>
#include "puzzle.h"
#include <map>
#include <queue>
using namespace std;

auto it = [](const Puzzle* a, const Puzzle* b) {

    if (a->h_cost + a->g_cost > b->h_cost + a->g_cost) {
        return true;
    }
    else {
        return false;
    }

};
map<Puzzle*, bool> visited;
priority_queue <Puzzle*, vector<Puzzle*>, decltype(it)> Q(it);

bool isVisited(Puzzle* node) {
    if (visited[node] == true) {
        return true;
    }
    return false;
}
bool goal(Puzzle* node) {

    vector<int> pg{ 1,2,3,4,5,6,7,8,0 };
    if (node->state == pg) {
        return true;
    }
    return false;
}
int misplaced_tile(vector<int> a) {
    return 0;

}
int manhattan(vector<int> a)
{
    return 0;
}
void general_search(Puzzle* root, int algorithm) {
    priority_queue<Puzzle*> q;
    q.push(root);
    while (1) {
        if (q.empty()) {
            cout << "Failure";
            break;
        }

    }
}
int main()
{
    Puzzle* puzzle = new Puzzle;
    vector<int> tile;
    Puzzle* gol = new Puzzle;
    int temp;
    cout << "Welcome to my 8-puzzle solver.\n";
    cout << "Enter your puzzle in the following format: 0 1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < 9; i++) {
        cin >> temp;
        tile.push_back(temp);
    }
    puzzle->setPuzzle(tile);
    int choice;
    cout << "Choose algorithm, 1 for Uniform Cost Search, 2 for A* Misplaced Tile, 3 for A* Manhattan Dist\n";
    cin >> choice;
    //Q.push(puzzle);
    //cout << choice;

    //puzzle->printPuzzle();
    //cout<<puzzle->findEmpty();
    //cout << goal(puzzle)<<"\n";
    
    //if (isVisited(puzzle)) {
    //    cout << " Has been visited";
    //}
    //gol->move_up(puzzle)->printPuzzle();
    //gol->move_down(puzzle)->printPuzzle();
    //gol->move_left(puzzle)->printPuzzle();
    //gol->move_right(puzzle)->printPuzzle();
    return 0;
}