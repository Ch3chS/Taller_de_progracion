#include "BranchAndBound.h"

int main(){
    

    // ---------- Probando Branch and Bound para archivos sin restricciones enteras (Simplex) --------------------------------------

    // lectura del archivo
    BranchAndBound B = BranchAndBound("./misc/MPI_2.txt");   // Se lee el archivo con el constructor (archivo sin restricciones enteras)
    vector<float> result = B.solve();                        // Se resuelve usando solve, que entregara el resultado de simplex

    // Comprobando resultado
    for(int i = 0; i < (int)result.size(); i++) cout << result.at(i) << " ";
    cout << "\n\n";


    // ---------- Probando Branch and Bound para archivo con restricciones enteras -------------------------------------------------


    return 0;
}