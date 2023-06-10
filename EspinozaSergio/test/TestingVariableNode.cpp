#include "VariableNode.h"

int main() {
    // Crear un NumberNode
    VariableNode* nodo1 = new VariableNode("x");
    VariableNode* nodo2 = new VariableNode("y");

    // Acceder a los valores
    cout << nodo1->getVariable() << endl;
    cout << nodo2->getVariable() << endl;

    // print
    nodo1->printTree();
    nodo2->printTree();

    delete nodo1;
    delete nodo2;

    return 0;
}