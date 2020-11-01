#ifndef TEO_PROYECTO_REVAUTOMATA_H
#define TEO_PROYECTO_REVAUTOMATA_H
#include "detautomata.h"
#include <iostream>
using namespace std;

struct RevAutomata {
    unordered_map<string, State*> states;
    vector<int> first_states;
    int final_state;
    explicit RevAutomata(const Automata& automata);
    void display();
    void clear();
    ~RevAutomata();
};

void RevAutomata::clear() {
    states.erase(states.begin(), states.end());
}

RevAutomata::~RevAutomata() {
    this->clear();
}

void RevAutomata::display() {
    cout<<this->states.size()<<" "<<this->first_states.size()<<" ";
    for(auto start: this->first_states) cout<<start<<" ";
    cout<<this->final_state<<" ";
    for(auto state: this->states){
        for(auto transition: state.second->transitions){
            cout<<endl;
            cout<<(*transition->states[0]).id<<" ";
            cout<<(*transition).data<<" ";
            cout<<(*transition->states[1]).id<<" ";
        }
    }
}

RevAutomata::RevAutomata(const Automata& automata) {
    final_state = automata.first_state;
    first_states = automata.final_states;
    this->states = automata.states;
    for(auto state: this->states){
        for(auto transiton: state.second->transitions)
            swap(transiton->states[0], transiton->states[1]);
    }
}

#endif //TEO_PROYECTO_REVAUTOMATA_H