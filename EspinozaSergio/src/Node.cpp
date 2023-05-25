#include "Node.h"

Node::Node() {
    type = INVALID;
}

Node::~Node() {
}

int Node::getType(){
    return type;
}

void Node::setType(int type){
    this->type = type;
}

void Node::printTree(){
    
}