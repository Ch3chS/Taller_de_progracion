#include "Node.h"

Node::Node(){
    this->upperBound = 0;
    this->lowerBound = 0;
    this->right = nullptr;
    this->left = nullptr;
}

Node::Node(float upperBound, float lowerBound){
    this->setUpperBound(upperBound);
    this->setLowerBound(lowerBound);
    this->right = nullptr;
    this->left = nullptr;
}

float Node::getUpperBound(){
    return this->upperBound;
}

float Node::getLowerBound(){
    return this->lowerBound;
}

Node *Node::getLeft(){
    return this->left;
}

Node *Node::getRight(){
    return this->right;
}



void Node::setUpperBound(float upperBound){
    this->upperBound = upperBound;
}

void Node::setLowerBound(float lowerBound){
    this->lowerBound = lowerBound;
}

void Node::setLeft(Node *node){
    this->left = node;
}

void Node::setRight(Node *node){
    this->right = node;
}