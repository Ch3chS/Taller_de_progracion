#ifndef SYMBOLICPROCESSOR_H
#define SYMBOLICPROCESSOR_H

#include <functional>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include "OperationNode.h"
#include "VariableNode.h"
#include "NumberNode.h"
#include "math.h"


/*
    * Clase SymbolicProcessor:
    * Clase que representa el procesador simbólico como tal, cuenta con un puntero a la raiz de un arbol sintáctico
    * para un fácil acceso al mismo y con funciones que permiten cargarlo y procesarlo.
*/
class SymbolicProcessor {
    private:
    Node* source;
    static map<char, function<int(int, int)>> operations;

    //Funciones auxiliares propias para calculos internos
    static int addition(int operand1, int operand2);
    static int subtraction(int operand1, int operand2);
    static int multiplication(int operand1, int operand2);

    //Funciones auxiliares para derivar
    Node* deriveAddition(OperationNode* node, string variable);
    Node* deriveSubtraction(OperationNode* node, string variable);
    Node* deriveMultiplication(OperationNode* node, string variable);
    Node* derivePow(OperationNode* node, string variable);

    // Funciones auxiliares para simplificar
    NumberNode* evaluateExpression(Node* expression);

public:
    // Getters
    Node* getSource();

    // Setters
    void setSource(Node* newSource);

    // Otros
    bool load(string filename);
    Node* deriveExpression(Node* node, string variable);
    Node* simplifyExpression(Node* expression);
};

#endif
