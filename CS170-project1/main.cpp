// 8puzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "puzzle.h"
#include <map>
#include <queue>
#include <stack>
#include <chrono>
using namespace std;

auto it = [](const Puzzle* a, const Puzzle* b) {

    if (a->h_cost + a->g_cost == b->h_cost + b->g_cost) {
        return a->g_cost > b->g_cost;
    }
    else {
        return a->h_cost + a->g_cost > b->h_cost + b->g_cost;
    }

};
map<vector<int>, bool> visited;
priority_queue <Puzzle*, vector<Puzzle*>, decltype(it)> Q(it);
stack<Puzzle*> path;
vector<int> pg{ 'A','N','G','E','L','I','C','a',48 };
int ixp = 0;
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
void path_taken(Puzzle* ans) {

    while (ans != NULL) {
        path.push(ans);
        ans = ans->parent;
    }
    while (!path.empty()) {
        path.top()->printPuzzle();
        path.pop();
    }
}
bool isSolvable(vector<int> a) {

    int inversion = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            auto it = find(pg.begin(), pg.end(), a[i]);
            int goal = it - pg.begin();
            auto cit = find(pg.begin(), pg.end(), a[j]);
            int cgoal = cit - pg.begin();
            if (a[i] == 48 || a[j] == 48) continue;
            if (goal > cgoal) {
                inversion++;
            }
        }
    }
    return inversion % 2 == 0;
}
int misplaced_tile(vector<int> a) {
    int cost = 0;
    for (int i = 0; i < 9; i++) {

        if (a[i] == 48) continue;
        if (a[i] != pg[i]) {
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
        if (a[i] != 48) {

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
    Puzzle* ps;
    visited.insert(pair<vector<int>, bool>(root->state, true));

    Q.push(root);
    //Puzzle* top = new Puzzle(Q.top());
    //top->printPuzzle();
    //cout << "\n Visited:" << isVisited(root);
    Puzzle* top = new Puzzle();
    while (!Q.empty()) {
        top = Q.top();

        if (goal(top) || goal(top->swapA())) {
            cout << "Found\n";
            path_taken(top);
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
                    ixp++;
                }
                if (top->move_down() != NULL && !isVisited(top->move_down()->state)) {
                    pd = new Puzzle(top->move_down());
                    pd->h_cost = 0;
                    Q.push(pd);
                    visited.insert(pair<vector<int>, bool>(pd->state, true));
                    ixp++;
                }
                if (top->move_left() != NULL && !isVisited(top->move_left()->state)) {
                    pl = new Puzzle(top->move_left());
                    pl->h_cost = 0;
                    Q.push(pl);
                    visited.insert(pair<vector<int>, bool>(pl->state, true));
                    ixp++;
                }
                if (top->move_right() != NULL && !isVisited(top->move_right()->state)) {
                    pr = new Puzzle(top->move_right());
                    pr->h_cost = 0;
                    Q.push(pr);
                    visited.insert(pair<vector<int>, bool>(pr->state, true));
                    ixp++;
                }
                if (isSolvable(top->swapA()->state) && !isVisited(top->swapA()->state)) {
                    ps = new Puzzle(top->swapA());
                    ps->h_cost = 0;
                    Q.push(ps);
                    visited.insert(pair<vector<int>, bool>(ps->state, true));
                    ixp++;
                }
            }
            else if (algorithm == 2) {
                if (top->move_up() != NULL && !isVisited(top->move_up()->state)) {
                    pu = new Puzzle(top->move_up());
                    pu->h_cost = misplaced_tile(pu->state);
                    Q.push(pu);
                    visited.insert(pair<vector<int>, bool>(pu->state, true));
                    ixp++;
                }
                if (top->move_down() != NULL && !isVisited(top->move_down()->state)) {
                    pd = new Puzzle(top->move_down());
                    pd->h_cost = misplaced_tile(pd->state);
                    Q.push(pd);
                    visited.insert(pair<vector<int>, bool>(pd->state, true));
                    ixp++;
                }
                if (top->move_left() != NULL && !isVisited(top->move_left()->state)) {
                    pl = new Puzzle(top->move_left());
                    pl->h_cost = misplaced_tile(pl->state);
                    Q.push(pl);
                    visited.insert(pair<vector<int>, bool>(pl->state, true));
                    ixp++;
                }
                if (top->move_right() != NULL && !isVisited(top->move_right()->state)) {
                    pr = new Puzzle(top->move_right());
                    pr->h_cost = misplaced_tile(pr->state);
                    Q.push(pr);
                    visited.insert(pair<vector<int>, bool>(pr->state, true));
                    ixp++;
                }
                if (isSolvable(top->swapA()->state) && !isVisited(top->swapA()->state)) {
                    ps = new Puzzle(top->swapA());
                    ps->h_cost = misplaced_tile(ps->state);
                    Q.push(ps);
                    visited.insert(pair<vector<int>, bool>(ps->state, true));
                    ixp++;
                }
            }
            else if (algorithm == 3) {
                if (top->move_up() != NULL && !isVisited(top->move_up()->state)) {
                    pu = new Puzzle(top->move_up());
                    pu->h_cost = manhattan(pu->state);
                    Q.push(pu);
                    visited.insert(pair<vector<int>, bool>(pu->state, true));
                    ixp++;
                }
                if (top->move_down() != NULL && !isVisited(top->move_down()->state)) {
                    pd = new Puzzle(top->move_down());
                    pd->h_cost = manhattan(pd->state);
                    Q.push(pd);
                    visited.insert(pair<vector<int>, bool>(pd->state, true));
                    ixp++;
                }
                if (top->move_left() != NULL && !isVisited(top->move_left()->state)) {
                    pl = new Puzzle(top->move_left());
                    pl->h_cost = manhattan(pl->state);
                    Q.push(pl);
                    visited.insert(pair<vector<int>, bool>(pl->state, true));
                    ixp++;
                }
                if (top->move_right() != NULL && !isVisited(top->move_right()->state)) {
                    pr = new Puzzle(top->move_right());
                    pr->h_cost = manhattan(pr->state);
                    Q.push(pr);
                    visited.insert(pair<vector<int>, bool>(pr->state, true));
                    ixp++;
                }
                if (isSolvable(top->swapA()->state) && !isVisited(top->swapA()->state)) {
                    ps = new Puzzle(top->swapA());
                    ps->h_cost = manhattan(ps->state);
                    Q.push(ps);
                    visited.insert(pair<vector<int>, bool>(ps->state, true));
                    ixp++;
                }
            }
        }

    }
}
int main()
{
    Puzzle* puzzle = new Puzzle;

    vector<int> tile;
    Puzzle* gol = new Puzzle;
    char temp;
    cout << "Welcome to my 8-puzzle solver.\n";
    cout << "Enter your puzzle in the following format: 0 1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < 9; i++) {
        cin >> temp;
        tile.push_back(temp);

    }
    puzzle->setPuzzle(tile);
    int choice;
    cout << "Choose your algorithm:\n";
    cout << "Enter 1. Uniform Cost Search\n";
    cout << "Enter 2. A* with Misplaced Tile Heuristics\n";
    cout << "Enter 3. A* with Manhattan Distance Heuristics\n";
    cin >> choice;
    auto begin = chrono::high_resolution_clock::now();
    //puzzle->printPuzzle();
    if (isSolvable(puzzle->state)) {
        general_search(puzzle, choice);
    }
    else if (isSolvable(puzzle->swapA()->state)) {
        puzzle = puzzle->swapA();
        general_search(puzzle, choice);
    }

    //cout << isSolvable(puzzle->state);
    //cout<<goal(puzzle);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cout << "\n";
    printf("Execution Time: %.3f seconds.\n", elapsed.count() * 1e-9);
    cout << "Number of expanded node: " << ixp;
    //cout << isSolvable(puzzle->state);
    //vector<int> l(puzzle->findA());
    //for (int i = 0; i < 2; i++) {
    //    cout << l[i]<<" ";
    //}
    //cout << "Manhattan cost:" << manhattan(tile);
    //cout << "\n";
    //cout << "Misplaced cost:" << misplaced_tile(tile);
    //cout << goal(puzzle)<<"\n";

    //if (isVisited(puzzle)) {
    //    cout << " Has been visited";
    //}
    //puzzle->move_up()->printPuzzle();
    //puzzle->move_down()->printPuzzle();
    //puzzle->move_left()->printPuzzle();
    //puzzle->move_right()->printPuzzle();
    //cout<<goal((puzzle->swapA()));
    //Puzzle* pu = new Puzzle(puzzle->move_up());
    //pu->printPuzzle();
    //cout << pu->g_cost;
    //pu->parent->printPuzzle();
    //Puzzle* pd = new Puzzle(pu->move_down());
    //pd->printPuzzle();
    //cout << pu->cost;
    //visited.insert(pair<vector<int>,bool>(puzzle->state,true));
    //if (isVisited(pd->state)) {
    //    cout << "Visited\n ";
    //}
    return 0;
}


