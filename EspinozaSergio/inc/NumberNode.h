#ifndef NUMBER_NODE_H
#define NUMBER_NODE_H

#include "Node.h"

/*
    * Clase NumberNode:
    * Esta clase representa una hoja del árbol sintáctico, específicamente del tipo número entero,
    * es decir, dentro de la notación polaca este un número entero cualquiera (>= 0).  
*/
class NumberNode : public Node {
private:
    int value;

public:
    // Constructor
    NumberNode(int value);

    // Destructor
    ~NumberNode();

    // Getters
    int getValue() const;

    // Otros
    void printTree() override;
};

#endif
