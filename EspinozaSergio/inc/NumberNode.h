#ifndef NUMBER_NODE_H
#define NUMBER_NODE_H

#include "Node.h"

class NumberNode : public Node {
private:
    int value;

public:
    NumberNode(int value);
    ~NumberNode();

    int getValue() const;
    void printTree() override;
};

#endif
