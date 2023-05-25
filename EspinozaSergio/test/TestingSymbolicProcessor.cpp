#include <iostream>
#include "SymbolicProcessor.h"
#include "OperationNode.h"

using namespace std;

int main() {
    // Crear una instancia de SymbolicProcessor
    SymbolicProcessor processor;

    // Cargar el árbol sintáctico desde un archivo
    if (processor.load("./misc/expr2.txt")) {
        std::cout << "Cargado!\n\n";

        processor.getSource()->printTree();

        cout << "\n\n";

        return 0;
    }
    cout << "No se pudo cargar el archivo";
    return 1;
}
