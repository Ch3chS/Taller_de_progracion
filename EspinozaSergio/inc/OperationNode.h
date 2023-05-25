#ifndef OPERATION_NODE_H
#define OPERATION_NODE_H

#include <iostream>
#include "Node.h"

class OperationNode : public Node {
private:
    char operation;
    Node* left;
    Node* right;

public:
    OperationNode(char operation, Node* left, Node* right);
    OperationNode(char operation);
    ~OperationNode();

    char getOperation() const;
    Node* getLeft() const;
    Node* getRight() const;
    void setLeft(Node* left);
    void setRight(Node* right);
    void printTree() override;
};

#endif

