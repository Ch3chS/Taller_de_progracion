#include "Node.h"

int main(){
    // Probando constructor vacio
    Node *node = new Node();

    // Probando constructor con lowerBound y upperBound, además de los setters de right y left
    node->setLeft(new Node(5000, 100));
    node->setRight(new Node(1500, 1000));

    // Imprimiendo resultado
    cout << "UpperBound: " << node->getUpperBound() << ", LowerBound " << node->getLowerBound() << endl;
    cout << "Izq UpperBound: " << node->getLeft()->getUpperBound() << ", Izq LowerBound " << node->getLeft()->getLowerBound() << endl;
    cout << "Der UpperBound: " << node->getRight()->getUpperBound() << ", Der LowerBound " << node->getRight()->getLowerBound() << endl;

    // Probando setters de lowerBound y upperBound
    node->setLowerBound(500);
    node->setUpperBound(600);    
    cout << "UpperBound: " << node->getUpperBound() << ", LowerBound " << node->getLowerBound() << endl;

    return 0;
}