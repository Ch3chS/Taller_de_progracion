#ifndef NODE_H
#define NODE_H

#include "Simplex.h"
#include "Restrictions.h"
#include <limits>

using namespace std;

// Clase que contiene el problema

class Node {
    private:
        Node* left;
        Node* right;

        int N, m1, m2, m3;
        vector<int> enteros;
        vector<float> coeficientes_f;
        Restrictions *restrictions_m1, *restrictions_m2, *restrictions_m3;

        float upperBound;
        float lowerBound;
        float Z;

    public:
        int getN();
        int getM1();
        int getM2();
        int getM3();
        vector<int> getEnteros();
        vector<float> getCoef();
        vector<vector<float>> getRestrictions();

        bool load(string filename);
        vector<float> simplex();
        vector<float> solve();  //Resuelve simplex
        //isFeasible(); Es factible?
        //Branch(); izquierda y derecha

        float calculateObjective(const vector<float>& solution);
        bool isIntegerSolution(const vector<float>& solution);
        pair<Node*, Node*> branch();

        void printMatriz(vector<vector<float>> m);
};

#endif