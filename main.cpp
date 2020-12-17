#include "lib.h"
#include "detautomata.h"
#include "minafd.h"
#include "revautomata.h"
#include "equivalencia.h"
#include "brozozowski.h"
#include <ctime>
#include <iomanip>

int main() {
    unsigned t0, t1;
    auto a = Automata();
    a.readInput();
<<<<<<< HEAD

    t0 = clock();
    cout<<"  1 - Brzozowski: "<<endl;
    //auto Brozozowski = Brzozowski(a);t1 = clock();
    //Brozozowski.display(); cout<<endl;
    //double time = (double(t1-t0)/CLOCKS_PER_SEC);
    //cout << "Execution Time: " << time << endl << endl;


    t0 = clock();
    cout<<"  2 - Matriz de Equivalencia (O(n^4)): "<<endl;
    auto Matriz_equivalencia = equivalenciaEstados(a);
    t1 = clock();
    printMatrizEquivalencia(Matriz_equivalencia); cout<<endl;
/*    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << std::setprecision(8) << time << endl << endl;*/

    t0 = clock();
    cout<<"  3 - Matriz de Equivalencia (O(n^2)): "<<endl;
    auto Matriz_equivalencia_mejorada = equivalencia_optimizada(a);
    t1 = clock();
    printMatrizEquivalencia(Matriz_equivalencia_mejorada); cout<<endl;
/*    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << std::setprecision(8) << time << endl << endl;*/

    t0 = clock();
    cout<<"  4 - Huffman-Moore: "<<endl;
    auto Huffman_Moore = HuffMore(a);
    t1 = clock();
    Huffman_Moore.display(); cout<<endl;
/*    time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << std::setprecision(8) << time << endl << endl;
    cout<<endl;*/

=======
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
>>>>>>> fea9400d0b02ae18b57fc9e1b19aa5c8cdd51a46
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