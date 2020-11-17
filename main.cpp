#include "lib.h"
#include "detautomata.h"
#include "revautomata.h"
#include "equivalencia.h"
#include "brozozowski.h"

int main() {
    auto a = Automata();
    a.readInput();
    //a.display();
    //auto b = Brzozowski(a);
    //b.display();
    //cout<<endl;
    printMatrizEquivalencia(equivalenciaEstados(a));
    return 0;
}