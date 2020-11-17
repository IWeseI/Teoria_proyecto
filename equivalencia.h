#ifndef TEO_PROYECTO_EQUIVALENCIA_H
#define TEO_PROYECTO_EQUIVALENCIA_H

#include "detautomata.h"
#include "lib.h"
vector<vector<bool>> equivalencia (const Automata& a){
    int n = a.states.size();
    vector<vector<bool>> out {};
    Transition* zero_I_transition;
    Transition* one_I_transition;
    Transition* zero_J_transition;
    Transition* one_J_transition;
    for (auto state_i: a.states) {
        vector<bool> temp;
        auto i_transition = state_i.second->transitions[0];
        switch(i_transition->data){
            case 0: {
                zero_I_transition = i_transition;
                one_I_transition = state_i.second->transitions[1];
                break;
            }
            case 1: {
                zero_I_transition = state_i.second->transitions[1];
                one_I_transition = i_transition;
                break;
            }
            default: throw out_of_range("ERROR: El Automata no es un AFD");
        }
        for (auto state_j: a.states) {
            auto j_transition = state_j.second->transitions[0];
            switch(j_transition->data){
                case 0: {
                    zero_J_transition = j_transition;
                    one_J_transition = state_j.second->transitions[1];
                    break;
                }
                case 1: {
                    zero_J_transition = state_j.second->transitions[1];
                    one_J_transition = j_transition;
                    break;
                }
                default: throw out_of_range("ERROR: El Automata no es un AFD");
            }
            temp.push_back((zero_I_transition->states[1]->id == zero_J_transition->states[1]->id) && (one_I_transition->states[1]->id == one_J_transition->states[1]->id));
        }
        out.push_back(temp);
    }
    return out;
}

vector<vector<bool>> equivalenciaEstados(const Automata& a){
    vector<vector<bool>> out {};
    vector<pair<int,int>> dist {};
    //Se llena out con TRUE
    for(int i = 0; i < a.states.size(); i++){
        vector<bool> temp {};
        for(int j = 0; j < a.states.size(); j++) {
            temp.push_back(true);
        }
        out.push_back(temp);
    }
    int i {}, j {};
    // Caso base
    for(auto state_i: a.states){
        j = 0;
        for(auto state_j: a.states){
            bool c1 = find(a.finalStates.begin(), a.finalStates.end(), state_i.first) == a.finalStates.end();
            bool c2 = find(a.finalStates.begin(), a.finalStates.end(), state_j.first) == a.finalStates.end();
            if((c1 && !c2) || (!c1 && c2)){
                out[i][j] = false;
                dist.emplace_back(state_i.first, state_j.first);
            }
            j++;
        }
        i++;
    }
    //Caso iterativo
    auto dist_size = dist.size();
    do {
        dist_size = dist.size();
        i = 0;
        for (auto state_i: a.states) {
            j = 0;
            for (auto state_j: a.states) {
                if(out[i][j]) {
                    Transition *zero_I_transition;
                    Transition *one_I_transition;
                    Transition *zero_J_transition;
                    Transition *one_J_transition;
                    auto i_transition = state_i.second->transitions[0];
                    switch (i_transition->data) {
                        case 0: {
                            zero_I_transition = i_transition;
                            one_I_transition = state_i.second->transitions[1];
                            break;
                        }
                        case 1: {
                            zero_I_transition = state_i.second->transitions[1];
                            one_I_transition = i_transition;
                            break;
                        }
                        default:
                            throw out_of_range("ERROR: El Automata no es un AFD");
                    }
                    auto j_transition = state_j.second->transitions[0];
                    switch (j_transition->data) {
                        case 0: {
                            zero_J_transition = j_transition;
                            one_J_transition = state_j.second->transitions[1];
                            break;
                        }
                        case 1: {
                            zero_J_transition = state_j.second->transitions[1];
                            one_J_transition = j_transition;
                            break;
                        }
                        default:
                            throw out_of_range("ERROR: El Automata no es un AFD");
                    }
                    auto bothZeroTransitions = make_pair(zero_I_transition->states[1]->id,
                                                         zero_J_transition->states[1]->id);
                    auto bothOneTransitions = make_pair(one_I_transition->states[1]->id,
                                                        one_J_transition->states[1]->id);
                    bool c1 = find(dist.begin(), dist.end(), bothZeroTransitions) != dist.end();
                    bool c2 = find(dist.begin(), dist.end(), bothOneTransitions) != dist.end();
                    if (c1 || c2) {
                        out[i][j] = false;
                        dist.emplace_back(state_i.first, state_j.first);
                    }
                }
                j++;
            }
            i++;
        }
    } while (dist_size != dist.size());
    return out;
}

void printMatrizEquivalencia(const vector<vector<bool>>& matrix){
    for(const auto& row: matrix){
        for(auto col: row){
            cout<<(int) col<<" ";
        }
        cout<<endl;
    }
}

#endif //TEO_PROYECTO_EQUIVALENCIA_H