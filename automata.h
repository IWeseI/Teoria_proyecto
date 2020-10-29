#ifndef TEO_PROYECTO_AUTOMATA_H
#define TEO_PROYECTO_AUTOMATA_H

#include <iostream>
#include "state.h"
using namespace std;

class Automata {
private:
    unordered_map<int, State*> states;
    int first_state;
    list<int> final_states;
public:
    Automata();
    void processInput(int num_states);
    void display();
    void clear();
    ~Automata();

};

void Automata::display() {
    cout<<this->states.size()<<" "<<this->first_state<<" "<<this->final_states.size()<<" ";
    for(auto final: this->final_states) cout<<final<<" ";
    for(int i=0; i < this->states.size(); i++){
        for(auto transition: this->states[i]->transitions){
            cout<<endl;
            cout<<(*transition->states[0]).id<<" ";
            cout<<(*transition).data<<" ";
            cout<<(*transition->states[1]).id<<" ";
        }
    }
}

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
    processInput(2*num_states);
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
        auto transition = new Transition(data, this->states[id1], this->states[id2]);
        this->states[id1]->transitions.push_back(transition);
    }
}

#endif //TEO_PROYECTO_AUTOMATA_H