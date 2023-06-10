#include "NumberNode.h"

int main() {
    // Crear un NumberNode
    NumberNode* nodo1 = new NumberNode(1);
    NumberNode* nodo2 = new NumberNode(2);

    // Acceder a los valores
    cout << nodo1->getValue() << endl;
    cout << nodo2->getValue() << endl;

    // print
    nodo1->printTree();
    nodo2->printTree();

    delete nodo1;
    delete nodo2;

    return 0;
}