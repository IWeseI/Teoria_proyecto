#ifndef TEO_PROYECTO_REVAUTOMATA_H
#define TEO_PROYECTO_REVAUTOMATA_H
#include "detautomata.h"
#include <iostream>
using namespace std;

struct RevAutomata {
    map<int, State*> states;
    vector<int> firstStates;
    int finalState;
    explicit RevAutomata(const Automata& automata);
    void createTransition(int data, int id1, int id2);
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
    cout<<this->states.size()<<" "<<this->firstStates.size()<<" ";
    for(auto start: this->firstStates) cout<<start<<" ";
    cout<<this->finalState<<" ";
    for(const auto& state: this->states){
        for(auto transition: state.second->transitions){
            cout<<endl;
            cout<<(*transition->states[0]).id<<" ";
            cout<<(*transition).data<<" ";
            cout<<(*transition->states[1]).id<<" ";
        }
    }
}

RevAutomata::RevAutomata(const Automata& automata) {
    finalState = automata.firstState;
    firstStates = automata.finalStates;
    for (auto i : automata.states) {
        this->states[i.first] = new State(i.first);
    }
    for(const auto& state: automata.states){
        cout<<state.first<<": "<<endl;
        for(auto transiton: state.second->transitions) {
            //cout << transiton->states[0]->id << "->" << transiton->states[1]->id << endl;
            this->createTransition(transiton->data, state.first, transiton->states[1]->id);
        }
    }
}

void RevAutomata::createTransition(int data, int id1, int id2) {
    auto* t = new Transition(data, states[id2], states[id1]);
    states[id2]->transitions.push_back(t);
}

#endif //TEO_PROYECTO_REVAUTOMATA_H