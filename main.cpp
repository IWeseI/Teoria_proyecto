#include "lib.h"
#include "detautomata.h"
#include "revautomata.h"
#include "equivalencia.h"
#include "brozozowski.h"

int main() {
    auto a = Automata();
    a.readInput();
    auto b = Brzozowski(a);
    b.display();
    //printMatrizEquivalencia(equivalencia(a));
    return 0;
}