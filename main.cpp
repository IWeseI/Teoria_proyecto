#include "lib.h"
#include "detautomata.h"
#include "bettermatrix.h"
#include "revautomata.h"
#include "equivalencia.h"
#include "brozozowski.h"

int main() {
    auto a = Automata();
    a.readInput();
    auto xd = equivalencia_optimizada(a, equivalenciaEstados(a));
    //printMatrizEquivalencia(xd);}
    auto temp = dfs(a, 0, 4);
    for(auto i: temp.first) cout<<i.first<<" "<<i.second<<endl;
    //a.display();
    //auto b = Brzozowski(a);
    //b.display();
    cout<<endl;
    cout<<"-------------------------------"<<endl;
    printMatrizEquivalencia(equivalenciaEstados(a));
    return 0;
}