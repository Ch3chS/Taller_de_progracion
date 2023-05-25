#ifndef SYMBOLICPROCESSOR_H
#define SYMBOLICPROCESSOR_H

#include <string>
#include "Node.h"

class SymbolicProcessor {
public:
    Node* getSource();
    bool load(std::string filename);
    double evaluateExpression(Node* expression);
    Node* simplifyExpression(Node* expression);
    Node* differentiateExpression(Node* expression);

private:
    Node* source;
};

#endif
