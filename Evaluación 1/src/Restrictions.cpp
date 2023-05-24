#include "Restrictions.h"
using namespace std;


Restrictions::Restrictions(int n, int rnumber){
    this->restrictionsNumber = rnumber;
    this->n = n;
    this->restrictions = new bool*[rnumber];
    for(int i=0; i<rnumber; i++){
        this->restrictions[i] = new bool[n];
    }
}

void Restrictions::addRestriction(int rnumber, int item){
    this->restrictions[rnumber][item] = true;
}

void Restrictions::print(){
    for(int i = 0; i<this->restrictionsNumber; i++){
        for(int j = 0; j<this->n; j++){
            printf("%d ", this->restrictions[i][j]);
        }
        printf("\n");
    }
}

