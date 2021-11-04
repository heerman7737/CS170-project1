#include "puzzle.h"
#include <vector>
#include <iostream>
using namespace std;
Puzzle::Puzzle() {
    state = {};
    cost = 0;
    prev = 0;
    depth = 0;
    parent = NULL;

}

void Puzzle::setPuzzle(vector<int> tile) {
    for (int i = 0; i < 9; i++) {
        state.push_back(tile[i]);
    }
}
void Puzzle::printPuzzle() {
    if (this != NULL) {
        int temp = 0;
        for (int j = 0; j < 3; j++) {
            cout << "\n";
            for (int i = temp * 3; i < 3 * (temp + 1); i++) {
                cout << state[i] << " ";
            }
            temp++;
        }
        cout << "\n";
    }
}

int Puzzle::findEmpty() {
    for (int i = 0; i < 9; i++) {
        if (state[i] == 0) {
            return i;
        }
    }
    return -1;
}

bool Puzzle::compare(Puzzle* p1, Puzzle* p2) {
    bool result = true;
    for (int i = 0; i < 9; i++) {
        if (p1->state[i] != p2->state[i]) {
            result = false;
            break;
        }
    }
    return result;
}

Puzzle* Puzzle::move_up(Puzzle* node) {

    if (node->findEmpty() > 2) {
        Puzzle* result = new Puzzle;
        result->state = node->state;
        int pos = result->findEmpty();
        int temp = result->state[pos - 3];
        //cout << "temp:"<<temp<<"\n";
        result->state[pos - 3] = result->state[pos];
        result->state[pos] = temp;
        return result;
    }
    return NULL;
}
Puzzle* Puzzle::move_down(Puzzle* node) {
    if (node->findEmpty() < 6) {
        Puzzle* result = new Puzzle;
        result->state = node->state;
        int pos = result->findEmpty();
        int temp = result->state[pos + 3];
        //cout << "temp:"<<temp<<"\n";
        result->state[pos + 3] = result->state[pos];
        result->state[pos] = temp;
        return result;
    }
    return NULL;
}
Puzzle* Puzzle::move_left(Puzzle* node) {
    if (node->findEmpty() % 3 > 0) {
        Puzzle* result = new Puzzle;
        result->state = node->state;
        int pos = result->findEmpty();
        int temp = result->state[pos - 1];
        //cout << "temp:"<<temp<<"\n";
        result->state[pos - 1] = result->state[pos];
        result->state[pos] = temp;
        return result;
    }
    return NULL;
}
Puzzle* Puzzle::move_right(Puzzle* node) {
    if (node->findEmpty() % 3 < 2) {
        Puzzle* result = new Puzzle;
        result->state = node->state;
        int pos = result->findEmpty();
        int temp = result->state[pos + 1];
        //cout << "temp:"<<temp<<"\n";
        result->state[pos + 1] = result->state[pos];
        result->state[pos] = temp;
        return result;
    }
    return NULL;
}