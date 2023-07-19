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

void Node::setLowerBound(vector<float> result, vector<int> enteros, vector<float> coef){
    float lowerBound = 0;
    for(int i = 0; i < (int)enteros.size(); i++) {
        result.at(enteros.at(i)) = static_cast<int>(result.at(enteros.at(i)));
    }
    for(int i = 1; i < (int)result.size(); i++) {
        lowerBound += (result.at(i) * coef.at(i));
    }
    this->lowerBound = lowerBound;
}

void Node::setLeft(Node *node){
    this->left = node;
}

void Node::setRight(Node *node){
    this->right = node;
}