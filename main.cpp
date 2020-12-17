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

    return 0;
}