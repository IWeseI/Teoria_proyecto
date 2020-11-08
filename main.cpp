#include "lib.h"
#include "detautomata.h"
#include "revautomata.h"

/*string mergeElements(const vector<string>& vec){
    string output;
    for(const string& element: vec)
        output += element;
    return output;
}

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
*/

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

    map[cont++] = rev.first_states;
    a.first_state = 0;
    q.push(rev.first_states);

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
        for (auto j : i.second) {
            if (j == rev.final_state) a.final_states.push_back(i.first);
        }
    }

    for (auto i : a.final_states) {
        if (a.states.find(i) == a.states.end())
            a.final_states.erase(remove(a.final_states.begin(), a.final_states.end(), i), a.final_states.end());
    }

    return a;
}

Automata minimizeAFD(Automata a) {
    auto rev = RevAutomata(a);
    a = Converse(rev);
    rev = RevAutomata(a);
    return Converse(rev);
}

int main() {
    auto a = Automata();
    a.readInput();
    auto b = minimizeAFD(a);
    b.display();
    return 0;
}

/*
Pruebas:
3 0 1 1
0 0 1
0 1 0
1 0 2
1 1 1
2 0 1
2 1 2

5 0 2 1 3
0 0 1
0 1 3
1 0 2
1 1 1
2 0 1
2 1 2
3 0 4
3 1 3
4 0 3
4 1 4

6 0 2 3 4
0 0 1
0 1 2
1 0 2
1 1 3
2 0 2
2 1 4
3 0 3
3 1 3
4 0 4
4 1 4
5 0 5
5 1 4
*/