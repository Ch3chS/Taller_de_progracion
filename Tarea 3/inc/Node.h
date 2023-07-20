#ifndef NODE_H
#define NODE_H

#include "Simplex.h"
#include <vector>

using namespace std;

/*
    * Clase Node:
    * Esta clase representa un sub problema del problema de optimización, 
    * Posee cosas básicas para la creación de un arbol al juntar algunos de estos (ramas izquierda y derecha)
    * Además posee una cota superior y una inferior para confirmar si es la solución final del problema o no
*/
class Node {
    private:
        Node* left;
        Node* right;

        float upperBound;
        float lowerBound;

    public:
        // Constructores
        Node();
        Node(float upperBound, float lowerBound);

        // Getters
        float getUpperBound();
        float getLowerBound();
        Node *getLeft();
        Node *getRight();

        // Setters
        void setUpperBound(float upperBound);
        void setLowerBound(float lowerBound);
        void setLowerBound(vector<float> result, vector<int> enteros, vector<float> coef);
        void setLeft(Node *node);
        void setRight(Node *node);
};

#endif