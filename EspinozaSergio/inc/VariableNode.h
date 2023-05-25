#ifndef VARIABLE_NODE_H
#define VARIABLE_NODE_H

#include "Node.h"
#include <string>

class VariableNode : public Node {
private:
    std::string variable;

public:
    VariableNode(const std::string& variable);
    ~VariableNode();

    std::string getVariable() const;
    void setVariable(const std::string& variable);
    void printTree() override;
};

#endif
