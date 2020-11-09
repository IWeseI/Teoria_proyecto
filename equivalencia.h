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

void printMatrizEquivalencia(const vector<vector<bool>>& matriz){
    for(const auto& row: matriz){
        for(auto col: row){
            cout<<(int) col<<" ";
        }
        cout<<endl;
    }
}

#endif //TEO_PROYECTO_EQUIVALENCIA_H