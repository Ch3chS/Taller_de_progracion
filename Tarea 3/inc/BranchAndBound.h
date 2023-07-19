#ifndef BRANCHANDBOUND_H
#define BRANCHANDBOUND_H

#include "Node.h"

class BranchAndBound {
    private:
        int n, m, m1, m2, m3;
        Simplex *s;
        vector<int> enteros;
        vector<vector<float>> a;
        bool isSolved;
        Node *root;
        
    public:
        BranchAndBound(string filename);

        bool isFeasible(vector<float> result);
        bool isSolution(Node *node);
        int selectIndex(vector<float> result);

        void solve();
        vector<float> solve(Node *node, Simplex *s);
};

#endif