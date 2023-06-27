#ifndef RESTRICTIONS_H
#define RESTRICTIONS_H

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define LEQ 1 //Menor o igual que
#define GEQ 2 //Mayor o igual que
#define EQU 3 //Igual que

class Restrictions {
    private:
        int type;
        int size;
        vector<vector<float>> restrictions;
    public:
        Restrictions(int type);

        vector<vector<float>> getRestrictions();

        void addRestriction(stringstream& ss);
        vector<vector<float>> concatenateRestrictions(vector<vector<float>> r1, vector<vector<float>> r2, vector<vector<float>> r3);
};

#endif