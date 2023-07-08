#include "Restrictions.h"

Restrictions::Restrictions(int type){
    this->size = 0;
    this->type = type;
}

vector<vector<float>> Restrictions::getRestrictions(){
    return this->restrictions;
}

void Restrictions::addRestriction(stringstream& ss){
    float temp;
    vector<float> restriction;

    this->size += 1;

    while(ss >> temp){
        restriction.push_back(temp);
    }

    this->restrictions.push_back(restriction);
}

vector<vector<float>>  Restrictions::concatenateRestrictions(vector<vector<float>> r1, vector<vector<float>> r2, vector<vector<float>> r3){
    r1.insert(r1.end(), r2.begin(), r2.end());
    r1.insert(r1.end(), r3.begin(), r3.end());

    //Vector de 0s para Simplex
    vector<float> zeroes;
    for(int i = 0; i < (int)r1.at(0).size(); i++){
        zeroes.push_back(0.0);
    }
    r1.push_back(zeroes);
    return r1;
}