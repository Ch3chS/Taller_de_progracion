#ifndef NODE_H
#define NODE_H

#include "Simplex.h"
#include <limits>

using namespace std;

// Clase que contiene el problema

class Node {
    private:
        Node* left;
        Node* right;

        float upperBound;
        float lowerBound;

    public:
        Node();
        Node(float upperBound, float lowerBound);

        float getUpperBound();
        float getLowerBound();
        Node *getLeft();
        Node *getRight();

        void setUpperBound(float upperBound);
        void setLowerBound(float lowerBound);
        void setLeft(Node *node);
        void setRight(Node *node);
};

#endif