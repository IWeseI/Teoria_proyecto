#ifndef TEO_PROYECTO_MINAFD_H
#define TEO_PROYECTO_MINAFD_H
#include "bettermatrix.h"

unordered_map<int, bool> singleDFS(Automata& a){
    queue<int> visited {};
    unordered_map<int, bool> reached;
    visited.push(a.firstState);
    for(int i = 0; i < a.states.size(); i++)
        reached[i] = false;
    reached[a.firstState] = true;
    while(!visited.empty()){
        auto top = visited.front();
        for(int i: {0,1}){
            auto dest = a.states[top]->transitions[i]->states[1]->id;
            if(!reached[dest]) {
                visited.push(dest);
                reached[dest] = true;
            }
        }
        visited.pop();
    }
    return reached;
}

Automata HuffMore(Automata& a) {
    auto eqMatrix = equivalencia_optimizada(a);
    auto reachMap = singleDFS(a);
    bool* visited = new bool [a.states.size()];
    vector<vector<int>> infoAFD {};
    int stateName {}, auxCont {};
    unordered_map<int, vector<int>> stateRelationship;
    Automata minAFD;
    for(int i = 0; i < a.states.size(); i++){
        if(reachMap[i] && !visited[i]){
            bool isFinalState = false;
            if(find(a.finalStates.begin(), a.finalStates.end(), i) != a.finalStates.end())
                isFinalState = true;
            vector<bool> row = eqMatrix[i];
            vector<int> partition {};
            for(int j = 0; j < a.states.size(); j++){
                if(row[j] && !visited[j] && reachMap[j]){
                    partition.push_back(j);
                    visited[j] = true;
                }
            }
            infoAFD.push_back(partition);
            minAFD.createState(stateName);
            stateRelationship[stateName] = partition;
            if(isFinalState) minAFD.finalStates.push_back(stateName);
            stateName++;
        }
        visited[i] = true;
    }
    for(const auto& partition: infoAFD){
        vector<int> temp {}, zeroTransition {}, oneTransition {};
        for(auto s: partition){
            auto state = a.states[s];
            auto z = state->transitions[0]->states[1]->id, o = state->transitions[1]->states[1]->id;
            if(find(zeroTransition.begin(), zeroTransition.end(), z) == zeroTransition.end())
                zeroTransition.push_back(z);
            if(find(oneTransition.begin(), oneTransition.end(), o) == oneTransition.end())
                oneTransition.push_back(o);
        }
        bool c1 = false, c2 = false;
        for(int i = 0; i <= stateName; i++){
            for(auto single: stateRelationship[i]) {
                if (find(zeroTransition.begin(), zeroTransition.end(), single) != zeroTransition.end() && !c1) {
                    minAFD.createTransition(auxCont, i, 0);
                    c1 = true;
                }
                if (find(oneTransition.begin(), oneTransition.end(), single) != oneTransition.end() && !c2) {
                    minAFD.createTransition(auxCont, i, 1);
                    c2 = true;
                }
            }
        }
        sort(minAFD.states[auxCont]->transitions.begin(), minAFD.states[auxCont]->transitions.end(), [](Transition* a, Transition* b){
            return  a->data < b->data;
        });
        auxCont++;
    }
    return minAFD;
}

#endif //TEO_PROYECTO_MINAFD_H