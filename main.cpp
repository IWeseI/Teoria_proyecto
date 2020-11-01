#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include "detautomata.h"
#include "revautomata.h"
using namespace std;

/*string mergeElements(const vector<string>& vec){
    string output;
    for(const string& element: vec)
        output += element;
    return output;
}*/

Automata Converse(const RevAutomata& rev){
    unordered_map<int, priority_queue<int>> visitedKeys;
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
    }
}


int main() {
 /*   auto a = Automata();
    auto rev = RevAutomata(a);
    rev.display();
    cout<<endl;*/
    return 0;
}
