#ifndef TEO_PROYECTO_STATE_H
#define TEO_PROYECTO_STATE_H
#include "transition.h"
#include <string>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;
struct State {
    explicit State(int id);
    int id;
    vector<Transition*> transitions {};
};

State::State(int id): id(id) {};

#endif //TEO_PROYECTO_STATE_H