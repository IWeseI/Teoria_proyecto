#ifndef TEO_PROYECTO_TRANSITION_H
#define TEO_PROYECTO_TRANSITION_H

struct State;
// Alfabeto = {0,1}
struct Transition{
    Transition(int data, State* id1, State* id2);
    State* states[2] {};
    int data {};
    ~Transition();
};

Transition::Transition(int data, State *id1, State *id2) {
    this->data = data;
    this->states[0] = id1;
    this->states[1] = id2;
}

Transition::~Transition() {
   for(auto state: states)
       state = nullptr;
}

#endif //TEO_PROYECTO_TRANSITION_H