#ifndef TEO_PROYECTO_BROZOZOWSKI_H
#define TEO_PROYECTO_BROZOZOWSKI_H
#include "detautomata.h"
#include "revautomata.h"
#include <queue>
#include <algorithm>

bool areEqual(vector<int> v1, vector<int> v2) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return v1 == v2;
}

int findId(unordered_map<int, vector<int>> map, vector<int> vec) {
    for (int i = 0; i < map.size(); ++i) {
        if (areEqual(map[i], vec)) return i;
    }
    return -1;
}

Automata Converse(RevAutomata& rev){
    Automata a;
    unordered_map<int, vector<int>> map;
    queue<vector<int>> q;
    int cont = 0;

    map[cont++] = rev.firstStates;
    a.firstState = 0;
    q.push(rev.firstStates);

    while (!q.empty()) {
        vector<int> temp = q.front();
        a.createState(findId(map, temp));
        vector<int> zero;
        vector<int> one;
        q.pop();

        for (int & i : temp) {
            auto t = rev.states[i]->transitions;
            for (auto & j : t) {
                if (j->data == 0) zero.push_back(j->states[1]->id);
                else one.push_back(j->states[1]->id);
            }
        }

        bool isZero = false;
        bool isOne = false;

        for (int i = 0; i < map.size(); ++i) {
            if (areEqual(map[i], zero)) isZero = true;
            if (areEqual(map[i], one)) isOne = true;
        }

        if (!isZero) {
            map[cont++] = zero;
            q.push(zero);
            a.createState(findId(map, zero));
        }
        if (!isOne) {
            map[cont++] = one;
            q.push(one);
            a.createState(findId(map, one));
        }

        a.createTransition(findId(map, temp), findId(map, zero), 0);
        a.createTransition(findId(map, temp), findId(map, one), 1);
    }

    for (const auto& i : map) {
        for (auto j : i.second)
            if (j == rev.finalState) a.finalStates.push_back(i.first);
    }

    for (auto i : a.finalStates) {
        if (a.states.find(i) == a.states.end())
            a.finalStates.erase(remove(a.finalStates.begin(), a.finalStates.end(), i), a.finalStates.end());
    }

    return a;
}

Automata Brzozowski(Automata a) {
    auto rev = RevAutomata(a);
    a = Converse(rev);
    rev = RevAutomata(a);
    return Converse(rev);
}

#endif //TEO_PROYECTO_BROZOZOWSKI_H