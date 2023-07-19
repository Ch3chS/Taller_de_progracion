#include "BranchAndBound.h"

int main(){
    

    // ---------- Probando Branch and Bound para archivos sin restricciones enteras (Simplex) --------------------------------------

    BranchAndBound B = BranchAndBound("./misc/MPI_2.txt");   // Se lee el archivo con el constructor (archivo sin restricciones enteras)
    B.solve();                        // Se resuelve usando solve, que entregara el resultado de simplex

    // ---------- Probando Branch and Bound para archivo con restricciones enteras -------------------------------------------------

    BranchAndBound B2 = BranchAndBound("./misc/MPI_1.txt");   // Se lee el archivo con el constructor (archivo con restricciones enteras)
    B2.solve();                        // Se resuelve usando solve, que entregara el resultado de la ramificación y poda

    return 0;
}