#ifndef OPERATION_NODE_H
#define OPERATION_NODE_H

#include "Node.h"

/*
    * Clase OperationNode:
    * Esta clase un nodo intermedio del árbol sintáctico, específicamente del tipo operación,
    * es decir, dentro de la notación polaca este sería una operación.
    * 
    * La clase cuenta con un char con el tipo de operación (+, -, *, ^) y dos nodos hijos que 
    * pueden ser de tipo OperationNode, VariableNode o NumberNode (izquierdo y derecho).
*/
class OperationNode : public Node {
private:
    char operation;
    Node* left;
    Node* right;

public:
    // Constructores
    OperationNode(char operation, Node* left, Node* right);
    OperationNode(char operation);

    // Destructor
    ~OperationNode();

    // Getters
    char getOperation() const;
    Node* getLeft() const;
    Node* getRight() const;

    // Setters
    void setLeft(Node* left);
    void setRight(Node* right);

    // Otros
    void printTree() override;
};

#endif

