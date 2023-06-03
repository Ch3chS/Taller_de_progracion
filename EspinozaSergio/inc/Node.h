#ifndef NODE_H
#define NODE_H

#include<iostream>

using namespace std;

class Node{
#define NUMBER 0
#define OPERATOR 1
#define VARIABLE 2
#define INVALID 3

private:
    int type;

public:
    Node();
    virtual ~Node();
    int getType();
    void setType(int type);
    virtual void printTree();
};

#endif