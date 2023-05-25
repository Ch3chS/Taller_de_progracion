#include <iostream>
#include "OperationNode.h"

int main() {
    // Crear un árbol sintáctico de ejemplo
    OperationNode* nodo1 = new OperationNode('+', new OperationNode('5', nullptr, nullptr), new OperationNode('3', nullptr, nullptr));
    OperationNode* nodo2 = new OperationNode('*', new OperationNode('6', nullptr, nullptr), new OperationNode('4', nullptr, nullptr));
    OperationNode* nodo3 = new OperationNode('-', nodo1, nodo2);

    // Acceder a los valores del árbol sintáctico
    char operadorRaiz = nodo2->getOperation();
    OperationNode* nodoIzquierda = dynamic_cast<OperationNode*>(nodo2->getLeft());
    OperationNode* nodoDerecha = dynamic_cast<OperationNode*>(nodo2->getRight());

    // Imprimir los valores del árbol sintáctico
    std::cout << "Operador de la raíz: " << operadorRaiz << std::endl;
    std::cout << "Nodo izquierdo: " << nodoIzquierda->getOperation() << std::endl;
    
    std::cout << "Nodo derecho: " << nodoDerecha->getRight() << std::endl;

    nodo3->printTree();

    std::cout << std::endl;

    delete nodo3;

    return 0;
}