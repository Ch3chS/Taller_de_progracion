#ifndef SYMBOLICPROCESSOR_H
#define SYMBOLICPROCESSOR_H

#include <functional>
#include <map>
#include <string>
#include "NumberNode.h"
#include "Node.h" // Incluye el archivo que define la clase Node

class SymbolicProcessor {
public:
    Node* getSource();
    void setSource(Node* newSource);
    bool getVariables();
    bool load(std::string filename);
    NumberNode* evaluateExpression(Node* expression);
    Node* simplifyExpression(Node* expression);
    Node* differentiateExpression(Node* expression);

private:
    Node* source;
    bool variables = false;
    static std::map<char, std::function<int(int, int)>> operations;

    //Funciones propias para calculos internos
    static int addition(int operand1, int operand2);
    static int subtraction(int operand1, int operand2);
    static int multiplication(int operand1, int operand2);
    static int division(int operand1, int operand2);
};

#endif
