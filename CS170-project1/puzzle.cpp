#include "puzzle.h"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
Puzzle::Puzzle() {
    state = {};
    h_cost = 0;
    g_cost = 0;
    parent = NULL;

}
Puzzle::Puzzle(vector<int> a) {
    state = a;
    h_cost = 0;
    g_cost = 0;
    parent = NULL;
}

Puzzle::Puzzle(Puzzle* p) {
    state = p->state;
    h_cost = p->h_cost;
    g_cost = p->g_cost;
    parent = p->parent;

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

                if (state[i] == 97) {
                    cout << (char)('A') << " ";
                }
                else {
                    cout << (char)state[i] << " ";
                }

            }
            temp++;
        }
        cout << "\n";
    }
}

int Puzzle::findEmpty() {
    for (int i = 0; i < 9; i++) {
        if (state[i] == 48) {
            return i;
        }
    }
    return -1;
}
vector<int> Puzzle::findA() {
    vector<int> result;
    int al;
    int an;
    for (int i = 0; i < 9; i++) {
        if (this->state[i] == 'A') {
            al = i;
        }
        if (this->state[i] == 'a') {
            an = i;
        }
    }
    result.push_back(al);
    result.push_back(an);
    return result;
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

Puzzle* Puzzle::move_up() {

    if (this->findEmpty() > 2) {
        Puzzle* result = new Puzzle;
        result->state = this->state;
        int pos = result->findEmpty();
        int temp = result->state[pos - 3];
        //cout << "temp:"<<temp<<"\n";
        result->state[pos - 3] = result->state[pos];
        result->state[pos] = temp;
        result->g_cost = this->g_cost + 1;
        result->h_cost = this->h_cost;
        result->parent = this;
        return result;
    }
    return NULL;
}
Puzzle* Puzzle::move_down() {
    if (this->findEmpty() < 6) {
        Puzzle* result = new Puzzle;
        result->state = this->state;
        int pos = result->findEmpty();
        int temp = result->state[pos + 3];
        //cout << "temp:"<<temp<<"\n";
        result->state[pos + 3] = result->state[pos];
        result->state[pos] = temp;
        result->g_cost = this->g_cost + 1;
        result->h_cost = this->h_cost;
        result->parent = this;
        return result;
    }
    return NULL;
}
Puzzle* Puzzle::move_left() {
    if (this->findEmpty() % 3 > 0) {
        Puzzle* result = new Puzzle;
        result->state = this->state;
        int pos = result->findEmpty();
        int temp = result->state[pos - 1];
        //cout << "temp:"<<temp<<"\n";
        result->state[pos - 1] = result->state[pos];
        result->state[pos] = temp;
        result->g_cost = this->g_cost + 1;
        result->h_cost = this->h_cost;
        result->parent = this;
        return result;
    }
    return NULL;
}
Puzzle* Puzzle::move_right() {
    if (this->findEmpty() % 3 < 2) {
        Puzzle* result = new Puzzle;
        result->state = this->state;
        int pos = result->findEmpty();
        int temp = result->state[pos + 1];
        //cout << "temp:"<<temp<<"\n";
        result->state[pos + 1] = result->state[pos];
        result->state[pos] = temp;
        result->g_cost = this->g_cost + 1;
        result->h_cost = this->h_cost;
        result->parent = this;
        return result;
    }
    return NULL;
}
Puzzle* Puzzle::swapA() {

    Puzzle* result = new Puzzle;
    vector<int> apos(this->findA());
    result->state = this->state;
    result->state[apos[0]] = this->state[apos[1]];
    result->state[apos[1]] = this->state[apos[0]];
    result->g_cost = this->g_cost;
    result->h_cost = this->h_cost;
    result->parent = this->parent;
    return result;

    return NULL;
}
