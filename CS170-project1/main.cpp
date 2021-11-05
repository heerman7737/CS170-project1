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
map<vector<int>, bool> visited;
priority_queue <Puzzle*, vector<Puzzle*>, decltype(it)> Q(it);
vector<int> pg{ 1,2,3,4,5,6,7,8,0 };
bool isVisited(vector<int> node) {
    if (visited.find(node) != visited.end()) {
        return true;
    }
    return false;
}
bool goal(Puzzle* node) {


    if (node->state == pg) {
        return true;
    }
    return false;
}
int misplaced_tile(vector<int> a) {
    int cost = 0;
    for (int i = 0; i < 9; i++) {

        if (a[i] == 0) continue;
        if (a[i] != i + 1) {
            cost++;
        }

    }
    return cost;


}
int manhattan(vector<int> a)
{
    int cost = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (a[i] != 0) {
            auto it = find(pg.begin(), pg.end(), a[i]);
            int goal = it - pg.begin();
            int goal_x = goal % 3;
            int goal_y = goal / 3;

            int curr_x = i % 3;
            int curr_y = i / 3;

            cost += abs(curr_x - goal_x) + abs(curr_y - goal_y);
        }

    }
    return cost;
}
void general_search(Puzzle* root, int algorithm) {
    Puzzle* pu;
    Puzzle* pd;
    Puzzle* pr;
    Puzzle* pl;
    visited.insert(pair<vector<int>, bool>(root->state, true));

    Q.push(root);
    //Puzzle* top = new Puzzle(Q.top());
    //top->printPuzzle();
    //cout << "\n Visited:" << isVisited(root);
    Puzzle* top = new Puzzle();
    while (!Q.empty()) {
        top = Q.top();

        if (goal(top)) {
            cout << "Found\n";
            cout << "H_cost: " << top->h_cost << "\nG_cost: " << top->g_cost;
            Q.pop();
            break;
        }
        else {
            Q.pop();
            if (algorithm == 1) {
                if (top->move_up() != NULL && !isVisited(top->move_up()->state)) {
                    pu = new Puzzle(top->move_up());
                    pu->h_cost = 0;
                    Q.push(pu);
                    visited.insert(pair<vector<int>, bool>(pu->state, true));

                }
                if (top->move_down() != NULL && !isVisited(top->move_down()->state)) {
                    pd = new Puzzle(top->move_down());
                    pd->h_cost = 0;
                    Q.push(pd);
                    visited.insert(pair<vector<int>, bool>(pd->state, true));

                }
                if (top->move_left() != NULL && !isVisited(top->move_left()->state)) {
                    pl = new Puzzle(top->move_left());
                    pl->h_cost = 0;
                    Q.push(pl);
                    visited.insert(pair<vector<int>, bool>(pl->state, true));

                }
                if (top->move_right() != NULL && !isVisited(top->move_right()->state)) {
                    pr = new Puzzle(top->move_right());
                    pr->h_cost = 0;
                    Q.push(pr);
                    visited.insert(pair<vector<int>, bool>(pr->state, true));

                }
            }
            else if (algorithm == 2) {
                if (top->move_up() != NULL && !isVisited(top->move_up()->state)) {
                    pu = new Puzzle(top->move_up());
                    pu->h_cost = misplaced_tile(pu->state);
                    Q.push(pu);
                    visited.insert(pair<vector<int>, bool>(pu->state, true));
 
                }
                if (top->move_down() != NULL && !isVisited(top->move_down()->state)) {
                    pd = new Puzzle(top->move_down());
                    pd->h_cost = misplaced_tile(pd->state);
                    Q.push(pd);
                    visited.insert(pair<vector<int>, bool>(pd->state, true));

                }
                if (top->move_left() != NULL && !isVisited(top->move_left()->state)) {
                    pl = new Puzzle(top->move_left());
                    pl->h_cost = misplaced_tile(pl->state);
                    Q.push(pl);
                    visited.insert(pair<vector<int>, bool>(pl->state, true));
                  
                }
                if (top->move_right() != NULL && !isVisited(top->move_right()->state)) {
                    pr = new Puzzle(top->move_right());
                    pr->h_cost = misplaced_tile(pr->state);
                    Q.push(pr);
                    visited.insert(pair<vector<int>, bool>(pr->state, true));
                    
                }
            }
            else if (algorithm == 3) {
                if (top->move_up() != NULL && !isVisited(top->move_up()->state)) {
                    pu = new Puzzle(top->move_up());
                    pu->h_cost = manhattan(pu->state);
                    Q.push(pu);
                    visited.insert(pair<vector<int>, bool>(pu->state, true));
                    
                }
                if (top->move_down() != NULL && !isVisited(top->move_down()->state)) {
                    pd = new Puzzle(top->move_down());
                    pd->h_cost = manhattan(pd->state);
                    Q.push(pd);
                    visited.insert(pair<vector<int>, bool>(pd->state, true));
                    
                }
                if (top->move_left() != NULL && !isVisited(top->move_left()->state)) {
                    pl = new Puzzle(top->move_left());
                    pl->h_cost = manhattan(pl->state);
                    Q.push(pl);
                    visited.insert(pair<vector<int>, bool>(pl->state, true));
                    
                }
                if (top->move_right() != NULL && !isVisited(top->move_right()->state)) {
                    pr = new Puzzle(top->move_right());
                    pr->h_cost = manhattan(pr->state);
                    Q.push(pr);
                    visited.insert(pair<vector<int>, bool>(pr->state, true));
                    
                }
            }
        }

    }
}
int main()
{
    Puzzle* puzzle = new Puzzle;
    //Puzzle* gol;
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
    general_search(puzzle, choice);
    //cout << "Manhattan cost:" << manhattan(tile);
    //cout << "\n";
    //cout << "Misplaced cost:" << misplaced_tile(tile);
    //cout << goal(puzzle)<<"\n";
    //Q.push(puzzle);
    //cout << choice;

    //puzzle->printPuzzle();
    //cout<<puzzle->findEmpty();
    //cout << goal(puzzle)<<"\n";
    
    //if (isVisited(puzzle)) {
    //    cout << " Has been visited";
    //}
    //gol->move_up()->printPuzzle();
    //gol->move_down()->printPuzzle();
    //gol->move_left()->printPuzzle();
    //gol->move_right()->printPuzzle();
    return 0;
}