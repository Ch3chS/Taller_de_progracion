#include "VariableNode.h"
#include <iostream>

VariableNode::VariableNode(const std::string& variable){
    this->variable = variable;
    this->setType(VARIABLE);
}

VariableNode::~VariableNode() {}

std::string VariableNode::getVariable() const {
    return variable;
}


void VariableNode::setVariable(const std::string& variable) {
    this->variable = variable;
}

void VariableNode::printTree() {
    std::cout << variable << " ";
}
