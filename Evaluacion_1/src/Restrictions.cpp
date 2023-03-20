#include "Restrictions.h"
using namespace std;

Restrictions::Restrictions(int items){
    this->items = items;
    this->restrictions = new bool*[items];
    for(int i=0; i<items; i++){
        this->restrictions[i] = new bool[items];
    }
}

void Restrictions::addRestriction(int r1, int r2){
    this->restrictions[r1][r2] = true;
    this->restrictions[r2][r1] = true;
}

void Restrictions::print(){
    for(int i = 0; i<items; i++){
        for(int j = 0; j<items; j++){
            printf("%d ", this->restrictions[i][j]);
        }
        printf("\n");
    }
}