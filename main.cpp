#include "lib.h"
#include "detautomata.h"
#include "minafd.h"
#include "revautomata.h"
#include "equivalencia.h"
#include "brozozowski.h"

int main() {
    auto a = Automata();
    a.readInput();
    auto xd = equivalencia_optimizada(a);
    auto porfavor = HuffMore(a);
    porfavor.display();
    //printMatrizEquivalencia(xd);
    //auto temp = singleDFS(a);
    //for(int i = 0; i < a.states.size(); i++) cout<<temp[i]<<" ";
    //a.display();
/*    auto b = Brzozowski(a);
    b.display();*/
    cout<<endl;
    //cout<<"-------------------------------"<<endl;
    //printMatrizEquivalencia(equivalenciaEstados(a));
    return 0;
}