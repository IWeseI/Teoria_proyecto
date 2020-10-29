#ifndef TEO_PROYECTO_AUTOMATA_H
#define TEO_PROYECTO_AUTOMATA_H

#include <iostream>
#include "transition.h"
#include "state.h"
#include <string>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Automata {
private:
    unordered_map<int, State*> states;
    int first_state;
    list<int> final_states;
public:
    Automata();
    void processInput(int num_states);
    /*void insertVertex(int id, TV vertex) {
        Vertex <TV, TE> *vertextemp = new Vertex<TV, TE>;
        vertextemp->data = vertex;
        vertexes[id] = vertextemp;
    }

    void display() {
        for (auto it = vertexes.begin(); it != vertexes.end(); it++) {
            displayVertex(it->first);
        }
    }*/
    void clear();
    ~Automata();

};

auto automata = new Automata()
Automata::Automata() {
    int num_states {}, num_finals {};
    cin>>num_states;
    cin>>this->first_state;
    cin>>num_finals;
    while(num_finals--){
        int id {};
        cin>>id;
        this->final_states.push_back(id);
    }
    processInput(num_states);
}

void Automata::clear() {
    states.erase(states.begin(), states.end());
}

Automata::~Automata() {
    this->clear();
}

void Automata::processInput(int num_states) {
    while(num_states--){
        int id1 {}, data {}, id2 {};
        cin>>id1;
        cin>>data;
        cin>>id2;
        if(this->states.find(id1) == this->states.end()) {
            auto *s1 = new State(id1);
            this->states[id1] = s1;
        }
        if(this->states.find(id2) == this->states.end()) {
            auto *s2 = new State(id2);
            this->states[id2] = s2;
        }
        auto transition = Transition(data, this->states[id1], this->states[id2]);
    }
}

#endif //TEO_PROYECTO_AUTOMATA_H