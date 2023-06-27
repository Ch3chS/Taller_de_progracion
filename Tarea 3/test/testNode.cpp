#include "Node.h"

int main(){
    Node node;

    string filename = "./misc/MPI_1.txt";
    node.load(filename);


    // Se comprueba correcta carga de linea 1
    cout << node.getN() << " " << node.getM1() << " " << node.getM2() << " " << node.getM3() << "\n";

    // Se comprueba correcta carga de linea 2
    for(int i = 0; i < node.getN(); i++){
        cout << node.getEnteros().at(i) << " ";
    }
    cout << "\n";

    // Se comprueba correcta carga de linea 3
    for(int i = 0; i < node.getN(); i++){
        cout << node.getCoef().at(i) << " ";
    }
    cout << "\n";

    // Se comprueba correcta carga de restricciones
    node.printMatriz(node.getRestrictions());


    // Simplex
    vector<float> v;
    v = node.simplex();
    for(int i = 0; i < (int)v.size(); i++) cout << v.at(i) << " ";




    return 0;
}