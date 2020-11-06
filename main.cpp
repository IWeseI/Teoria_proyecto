#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <unordered_map>
#include "detautomata.h"
#include "revautomata.h"
using namespace std;

void remove_repeats(vector<int>& vec){
    set<int> set;
    for(auto element: vec) {
        set.insert(element);
    }
    vec ={};
    for(auto element: set){
        vec.push_back(element);
    }
}

State* create_state(vector<int>& vec, RevAutomata& rev){
    remove_repeats(vec);
    sort(vec.begin(), vec.end(), std::greater<>());
    string output;
    bool repite=false;
    for(const int& element: vec)
        output += to_string(element);
    auto new_output = stoi(output);
    auto new_state = new State(new_output);
    for(auto state: vec){
        for(auto transition: rev.states[state]->transitions){
            repite=false;
            for(auto transition2: new_state->transitions){
                if(transition->states[1]==transition2->states[1]&& transition->data==transition2->data){
                    repite=true;
                }
            }
            auto new_transition= new Transition(transition->data, new_state, transition->states[1]);
            if(!repite)new_state->transitions.push_back(new_transition);
        }
    }

    return new_state;
}

Automata Converse(RevAutomata& rev){
    /*unordered_map<int, priority_queue<int>> visitedKeys;
    int cont {};
    queue<priority_queue<int>> temp {};
    vector<int> zeroTransitions {};
    vector<int> oneTransitions {};
    priority_queue<int> pq {};
    for(auto stateid: rev.first_states)
        pq.push(stateid);
    visitedKeys[cont++] = pq;
    temp.push(pq);
    while(!temp.empty()){
        auto top = temp.front();
        for(auto q: top){
            for(auto transition: visitedKeys[q].second->transitions){

            }
        }
    }

    for(const auto& state: rev.states) {
        for(auto transition: state.second->transitions){

        }
    }*/

    auto automata = Automata();
    queue<State*> visited;
    auto state0 = create_state(rev.first_states, rev);
    automata.states[state0->id]= state0;
    automata.first_state = state0->id;
    visited.push(state0);
    while(!visited.empty()){
        vector<int> zeroTransitions {};
        vector<int> oneTransitions {};
        auto curr_state = visited.front();
        visited.pop();
        for(auto transition: curr_state->transitions){
            if(transition->data==0){
                zeroTransitions.push_back(transition->states[1]->id);
            } else
                oneTransitions.push_back(transition->states[1]->id);
        }
        auto state1 = create_state(zeroTransitions, rev);
        auto state2 = create_state(oneTransitions, rev);

        if(automata.states.find(state1->id)== automata.states.end()){
            automata.states[state1->id]= state1;
            visited.push(state1);
        }
        if(automata.states.find(state2->id)== automata.states.end()){
            automata.states[state2->id]= state2;
            visited.push(state2);
        }
    }
    return automata;
}


int main() {
    auto a = Automata();
    a.readInput();
    auto rev = RevAutomata(a);
    rev.display(); cout<<endl<<endl;
    auto automata = Converse(rev);
    automata.display();
    cout<<endl;
    return 0;
}
