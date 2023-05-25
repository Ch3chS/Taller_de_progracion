#include <iostream>
#include "SymbolicProcessor.h"

int main() {
    // Crear una instancia de SymbolicProcessor
    SymbolicProcessor processor;

    // Cargar el árbol sintáctico desde un archivo
    if (processor.load("./misc/expr1.txt")) {
        std::cout << "Cargado!\n\n";
        return 0;
    }

    //processor.getSource()->printTree();

    return 0;
}
