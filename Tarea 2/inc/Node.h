#ifndef NODE_H
#define NODE_H

#include<iostream>

using namespace std;

/*
    * Superclase Node:
    * Esta superclase representa los nodos del arbol sintáctico, este posee 3 subtipos: 
    * - OperationNode
    * - VariableNode
    * - NumberNode
    * Puede encontrar mayor información de estos en sus respectivos headers (.h)
*/
class Node{
#define NUMBER 0
#define OPERATOR 1
#define VARIABLE 2
#define INVALID 3

private:
    int type;

public:
    // Constructor
    Node();

    // Destructor
    virtual ~Node();

    // Getters
    int getType();

    // Setters
    void setType(int type);

    // Otros
    virtual void printTree();
};

#endif