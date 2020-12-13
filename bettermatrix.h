#ifndef TEO_PROYECTO_BETTERMATRIX_H
#define TEO_PROYECTO_BETTERMATRIX_H
#include "lib.h"
#include "detautomata.h"
#include "equivalencia.h"
//ABCDE -> AB AC AD BC BD CD
void dfs_recursivo(Automata a, State* first_state, State* second_state, vector<pair<int,int>>& pairVector, bool& distingishable);
pair<vector<pair<int,int>>, bool> dfs(Automata a, int first, int second);

vector<vector<bool>> equivalencia_optimizada(const Automata& a, vector<vector<bool>> xd){
    vector<vector<bool>> out {};
    for(auto i = 0; i < a.states.size(); i++){
        vector<bool> temp;
        for(auto j = 0; j < a.states.size(); j++){
            temp.push_back(i == j);
        }
        out.push_back(temp);
    }
    vector<pair<int,int>> pairVector {};
    auto it = a.states.begin();
    while(it != a.states.end()){
        auto inner_it = it;
        while(++inner_it != a.states.end()){
            pairVector.emplace_back((*it).first, (*inner_it).first);
        }
        it++;
    }
    set<pair<int,int>> visited {};
    for(auto pairIt: pairVector){
        int first = pairIt.first;
        int second = pairIt.second;
        if(visited.find(pairIt) == visited.end()) {
            auto pairOut = dfs(a, first, second);
            for (auto innerPairIt: pairOut.first) {
                out[innerPairIt.first][innerPairIt.second] = !pairOut.second;
                out[innerPairIt.second][innerPairIt.first] = !pairOut.second;
                cout<<endl;
            }
        }
    }
    return out;
};

pair<vector<pair<int,int>>, bool> dfs(Automata a, int first, int second){
    auto first_state = a.states[first];
    auto second_state = a.states[second];
    Transition* zero_first_transition;
    Transition* one_first_transition;
    Transition* zero_second_transition;
    Transition* one_second_transition;
    auto transition = first_state->transitions[0];
    switch(transition->data) {
        case 0:
            zero_first_transition = transition;
            one_first_transition = first_state->transitions[1];
            break;
        case 1:
            one_first_transition = transition;
            zero_first_transition = first_state->transitions[1];
            break;
        default: throw out_of_range("ERROR: El Automata no es un AFD");
    }
    transition = second_state->transitions[1];
    switch(transition->data) {
        case 0:
            zero_second_transition = transition;
            one_second_transition = first_state->transitions[1];
            break;
        case 1:
            one_second_transition = transition;
            zero_second_transition = first_state->transitions[1];
            break;
        default: throw out_of_range("ERROR: El Automata no es un AFD");
    }
    vector<pair<int,int>> outVector {};
    bool distingishable = false;
    dfs_recursivo(a, zero_first_transition->states[1], zero_second_transition->states[1], outVector, distingishable);
    dfs_recursivo(a, one_first_transition->states[1], one_second_transition->states[1], outVector, distingishable);
    return make_pair(outVector, distingishable);
}

void dfs_recursivo(Automata a, State* first_state, State* second_state, vector<pair<int,int>>& pairVector, bool& distingishable){
    bool c1 = find(a.finalStates.begin(), a.finalStates.end(), first_state->id) == a.finalStates.end();
    bool c2 = find(a.finalStates.begin(), a.finalStates.end(), second_state->id) == a.finalStates.end();
    bool c3 = find(pairVector.begin(), pairVector.end(), make_pair(first_state->id, second_state->id)) != pairVector.end();
    bool c4 = find(pairVector.begin(), pairVector.end(), make_pair(second_state->id, first_state->id)) != pairVector.end();
    if(((c1 && !c2) || (!c1 && c2)) || (!c3 || !c4)){
        if((c1 && !c2) || (!c1 && c2)) distingishable = true;
        return;
    }
    pairVector.emplace_back(first_state->id, second_state->id);
    Transition* zero_first_transition;
    Transition* one_first_transition;
    Transition* zero_second_transition;
    Transition* one_second_transition;
    auto transition = first_state->transitions[0];
    switch(transition->data) {
        case 0:
            zero_first_transition = transition;
            one_first_transition = first_state->transitions[1];
            break;
        case 1:
            one_first_transition = transition;
            zero_first_transition = first_state->transitions[1];
            break;
        default: throw out_of_range("ERROR: El Automata no es un AFD");
    }
    transition = second_state->transitions[1];
    switch(transition->data) {
        case 0:
            zero_second_transition = transition;
            one_second_transition = first_state->transitions[1];
            break;
        case 1:
            one_second_transition = transition;
            zero_second_transition = first_state->transitions[1];
            break;
        default: throw out_of_range("ERROR: El Automata no es un AFD");
    }
    dfs_recursivo(a, zero_first_transition->states[1], zero_second_transition->states[1], pairVector, distingishable);
    dfs_recursivo(a, one_first_transition->states[1], one_second_transition->states[1], pairVector, distingishable);
}
#endif //TEO_PROYECTO_BETTERMATRIX_H
