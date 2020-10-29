#ifndef TEO_PROYECTO_STATE_H
#define TEO_PROYECTO_STATE_H
#include "automata.h"

struct State {
    State(int id);
    int id;
    list<Transition*> transitions {};
};

State::State(int id): id(id) {};

#endif //TEO_PROYECTO_STATE_H