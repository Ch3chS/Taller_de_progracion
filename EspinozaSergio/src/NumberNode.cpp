#include "NumberNode.h"
#include <iostream>

NumberNode::NumberNode(int value){
    this->value = value;
    setType(NUMBER);
}

NumberNode::~NumberNode() {}

int NumberNode::getValue() const {
    return value;
}

void NumberNode::printTree() {
    std::cout << value << " ";
}
