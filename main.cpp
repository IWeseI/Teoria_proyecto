#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include "detautomata.h"
#include "revautomata.h"
using namespace std;

string mergeElements(const vector<string>& vec){
    string output;
    for(const string& element: vec)
        output += element;
    return output;
}

Automata Converse(const RevAutomata& rev){
    unordered_map<string, State*> states = rev.states;
    for(const auto& state: states) {
        vector<string> zeroKeys {};
        vector<string> oneKeys {};
        for(auto transition: state.second->transitions){
            if(transition->data == 0)
                zeroKeys.push_back((transition->states[1])->id);
            else
                oneKeys.push_back((transition->states[1])->id);
        }
        auto state0 = mergeElements(zeroKeys);
        auto state1 = mergeElements(zeroKeys);
    }
}


int main() {
 /*   auto a = Automata();
    auto rev = RevAutomata(a);
    rev.display();
    cout<<endl;*/
    return 0;
}
