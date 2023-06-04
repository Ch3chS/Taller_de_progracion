#ifndef VARIABLE_NODE_H
#define VARIABLE_NODE_H

#include "Node.h"

/*
    * Clase VariableNode:
    * Esta clase representa una hoja del árbol sintáctico, específicamente del tipo variable,
    * es decir, dentro de la notación polaca este sería una variable cualquiera.  
*/
class VariableNode : public Node {
private:
    string variable;

public:
    // Constructor
    VariableNode(const string& variable);

    // Destructor
    ~VariableNode();

    // Getters
    string getVariable() const;

    // Setters
    void setVariable(const string& variable);

    // Otros
    void printTree() override;
};

#endif
