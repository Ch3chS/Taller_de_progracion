#ifndef SYMBOLICPROCESSOR_H
#define SYMBOLICPROCESSOR_H

#include <functional>
#include <sstream>
#include <fstream>
#include <stack>
#include <map>
#include "OperationNode.h"
#include "VariableNode.h"
#include "NumberNode.h"
#include "math.h"


class SymbolicProcessor {
public:
    Node* getSource();
    void setSource(Node* newSource);
    bool getVariables();
    bool load(std::string filename);
    NumberNode* evaluateExpression(Node* expression);
    Node* simplifyExpression(Node* expression);
    Node* deriveExpression(Node* node, std::string variable);

private:
    Node* source;
    bool variables = false;
    static std::map<char, std::function<int(int, int)>> operations;

    //Funciones propias para calculos internos
    static int addition(int operand1, int operand2);
    static int subtraction(int operand1, int operand2);
    static int multiplication(int operand1, int operand2);

    //Funciones para derivar
    Node* deriveAddition(OperationNode* node, std::string variable);
    Node* deriveSubtraction(OperationNode* node, std::string variable);
    Node* deriveMultiplication(OperationNode* node, std::string variable);
    Node* derivePow(OperationNode* node, std::string variable);
};

#endif
