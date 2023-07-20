#ifndef BRANCHANDBOUND_H
#define BRANCHANDBOUND_H

#include <cmath>
#include "Node.h"
#include "Simplex.h"

/*
    * Clase BranchAndBound:
    * Esta clase representa un problema de optimización con restricciones de valor entero
    * para esto usa nodos para los sub-problemas y simplex para resolverlos
*/
class BranchAndBound {
    private:
        int n, m, m1, m2, m3;
        Simplex *simplex;
        vector<int> enteros;
        vector<float> finalResult;
        vector<vector<float>> a;
        bool isSolved;
        Node *root;
        
    public:
        // Constructores
        BranchAndBound();
        BranchAndBound(string filename);

        // Métodos auxiliares para solve
        bool isFeasible(vector<float> result);
        bool isSolution(Node *node);
        int selectIndex(vector<float> result); // Esta ayuda con la ramificación

        // solve
        void solve();
        vector<float> solve(Node *node, Simplex *s);
};

#endif