#ifndef BRANCHANDBOUND_H
#define BRANCHANDBOUND_H

#include "Node.h"

class BranchAndBound {
    private:
        int n, m, m1, m2, m3;
        vector<int> enteros;
        vector<vector<float>> a;
        bool isSolved;
        Node *root;
        
    public:
        BranchAndBound(string filename);
        vector<float> solve();
};

#endif