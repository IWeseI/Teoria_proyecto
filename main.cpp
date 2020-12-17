#include "lib.h"
#include "detautomata.h"
#include "minafd.h"
#include "revautomata.h"
#include "equivalencia.h"
#include "brozozowski.h"

int main() {
    auto a = Automata();
    a.readInput();
    //auto xd = equivalencia_optimizada(a);
    //auto porfavor = HuffMore(a);
    //porfavor.display();
    //printMatrizEquivalencia(xd);
    //auto temp = singleDFS(a);
    //for(int i = 0; i < a.states.size(); i++) cout<<temp[i]<<" ";
    //a.display();
/*    auto b = Brzozowski(a);
    b.display();*/
    //cout<<endl;
    //cout<<"-------------------------------"<<endl;
    printMatrizEquivalencia(equivalencia_optimizada(a));
    cout<<"-------------------------------"<<endl;
    auto b = Brzozowski(a);
    b.display();
    return 0;
}

/*
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

8 0 1 5
0 0 4
0 1 3
1 0 0
1 1 1
2 0 5
2 1 0
3 0 4
3 1 7
4 0 0
4 1 1
5 0 3
5 1 3
6 0 5
6 1 4
7 0 4
7 1 7

9 0 3 2 5 8
0 0 1
0 1 4
1 0 2
1 1 5
2 0 3
2 1 7
3 0 4
3 1 7
4 0 5
4 1 8
5 0 6
5 1 1
6 0 7
6 1 1
7 0 8
7 1 2
8 0 0
8 1 4
*/