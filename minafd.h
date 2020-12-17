#ifndef TEO_PROYECTO_MINAFD_H
#define TEO_PROYECTO_MINAFD_H

#include "bettermatrix.h"
#include <algorithm>

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

Automata Hopcroft(Automata a) {
    Automata minAFD;
    vector<set<int>> P, W;
    vector<int> alph = {0, 1};

    //initial partitions
    set<int> temp1;
    for (auto i : a.finalStates) temp1.insert(i);
    P.push_back(temp1);
    W.push_back(temp1);

    set<int> temp2;
    for (auto i : a.states) temp2.insert(i.first);
    for (auto i : a.finalStates) temp2.erase(i);
    P.push_back(temp2);
    W.push_back(temp2);

    //algorithm
    while (!W.empty()) {
        //choose and remove A from W
        set<int> A = W[W.size() - 1];
        W.pop_back();

        //for each c in alphabet
        for (auto i : alph) {
            //X is the set of states for which transition i leads to A
            set<int> X;
            for (auto j : a.states) {
                for (auto k : j.second->transitions) {
                    if (k->data == i && (A.find(k->states[1]->id) != A.end())) {
                        X.insert(j.first);
                    }
                }
            }

            //for each set Y in P
            for (auto Y : P) {
                set<int> intersect;
                set_intersection(X.begin(), X.end(), Y.begin(), Y.end(), inserter(intersect, intersect.begin()));

                //if X ∩ Y is nonempty and Y \ X is nonempty
                if (!intersect.empty() && (X != Y)) {
                    //replace Y in P by the two sets X ∩ Y and Y \ X
                    P.erase(remove(P.begin(), P.end(), Y), P.end());
                    P.push_back(intersect);
                    set<int> newY = Y;
                    for (auto j : intersect) newY.erase(j);
                    P.push_back(newY);

                    //if Y is in W
                    if (find(W.begin(), W.end(), Y) != W.end()) {
                        //replace Y in W by the same sets
                        W.erase(remove(W.begin(), W.end(), Y), W.end());
                        W.push_back(intersect);
                        W.push_back(newY);
                    }

                    else {
                        if (intersect.size() <= newY.size()) W.push_back(intersect); //add X ∩ Y to W
                        else W.push_back(newY); //add Y \ X to W
                    }
                }
            }
        }
    }

    //construct DFA from P
    unordered_map<int, set<int>> states;
    int cont = 0;

    for (auto i : P) {
        if (!i.empty()) {
            minAFD.createState(cont);
            states[cont++] = i;
        }
    }

    //create state transitions
    for (auto i : states) {
        auto it = i.second.begin();
        int zeroState;
        int oneState;

        for (auto j : a.states[*it]->transitions) {
            if (j->data == 0) zeroState = j->states[1]->id;
            else if (j->data == 1) oneState = j->states[1]->id;
        }

        for (auto j : states) {
            if (j.second.find(zeroState) != j.second.end())
                minAFD.createTransition(i.first, j.first, 0);

            if (j.second.find(oneState) != j.second.end())
                minAFD.createTransition(i.first, j.first, 1);
        }
    }

    //define first and final states
    for (auto i : states) {
        for (auto j : i.second) {
            if (find(a.finalStates.begin(), a.finalStates.end(), j) != a.finalStates.end()) {
                minAFD.finalStates.push_back(i.first); break;
            }
            if (j == a.firstState) {
                minAFD.firstState = i.first; break;
            }
        }
    }



    return minAFD;
}

#endif //TEO_PROYECTO_MINAFD_H