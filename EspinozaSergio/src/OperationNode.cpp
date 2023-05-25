#include <iostream>
#include "OperationNode.h"

OperationNode::OperationNode(char operation, Node* left, Node* right){
    this->operation = operation;
    this->left = left;
    this->right = right;
    setType(OPERATOR);
}

OperationNode::OperationNode(char operation) {
    this->operation = operation;
    left = nullptr;
    right = nullptr;
    setType(OPERATOR);
}

OperationNode::~OperationNode() {
    if (left != nullptr) {
        delete left;
    }
    
    if (right != nullptr) { 
        delete right;
    }
}


char OperationNode::getOperation() const {
    return operation;
}

Node* OperationNode::getLeft() const {
    return left;
}

Node* OperationNode::getRight() const {
    return right;
}

void OperationNode::setLeft(Node* left){
    this->left = left;
}

void OperationNode::setRight(Node* right){
    this->right = right;
}

void OperationNode::printTree(){
    std::cout << operation << " ";

    if (left != nullptr) {
        left->printTree();
    }

    if (right != nullptr) {
        right->printTree();
    }
}