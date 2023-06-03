#include "VariableNode.h"

VariableNode::VariableNode(const string& variable){
    this->variable = variable;
    this->setType(VARIABLE);
}

VariableNode::~VariableNode() {}

    string VariableNode::getVariable() const {
    return variable;
}

void VariableNode::setVariable(const string& variable) {
    this->variable = variable;
}

void VariableNode::printTree() {
    cout << variable << " ";
}
