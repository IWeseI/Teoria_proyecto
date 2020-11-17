#ifndef TEO_PROYECTO_DETAUTOMATA_H
#define TEO_PROYECTO_DETAUTOMATA_H

#include <iostream>
#include <map>
#include "state.h"
using namespace std;

struct Automata {
    map<int, State*> states;
    int firstState{};
    vector<int> finalStates;
    Automata();
    void createState(int key);
    void createTransition(int id1, int id2, int data);
    void readInput();
    void processInput(int num_states);
    void display();
    void clear();
    ~Automata();
};

void Automata::display() {
    cout<<this->states.size()<<" "<<this->firstState<<" "<<this->finalStates.size()<<" ";
    for(auto final: this->finalStates) cout<<final<<" ";
    for(auto state: this->states){
        for(auto transition: state.second->transitions){
            cout<<endl;
            cout<<(*transition->states[0]).id<<" ";
            cout<<(*transition).data<<" ";
            cout<<(*transition->states[1]).id<<" ";
        }
    }
}

Automata::Automata(){}

void Automata::clear() {
    states.erase(states.begin(), states.end());
}

Automata::~Automata() {
    this->clear();
}

void Automata::processInput(int num_states) {
    while(num_states--){
        int id1 {}, id2 {}, data{};
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
        auto transition = new Transition(data, this->states[id1], this->states[id2]);
        this->states[id1]->transitions.push_back(transition);
    }
}

void Automata::readInput() {
    int num_states {}, num_finals {};
    cin>>num_states;
    cin>>this->firstState;
    cin>>num_finals;
    while(num_finals--){
        int id {};
        cin>>id;
        this->finalStates.push_back(id);
    }
    processInput(2*num_states);
}

void Automata::createState(int key) {
    states[key] = new State(key);
}

void Automata::createTransition(int id1, int id2, int data) {
    auto* t = new Transition(data, states[id1], states[id2]);
    states[id1]->transitions.push_back(t);
}

#endif //TEO_PROYECTO_DETAUTOMATA_H