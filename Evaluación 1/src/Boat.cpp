#include <stdio.h>
#include "Boat.h"
#include "Restrictions.h"

// El bote almacena el número de item, no el arreglo completo

Boat::Boat(int size){
    this->size = size;
    this->items = 0;
    this->boat = new int[size];
}

Boat::~Boat(){

}

bool Boat::isFull(){
    if(items == size){
        return true;
    }
    return false;
}

void Boat::addItem(int item){
    this->boat[items] = item;
    this->items++;
}


State *Boat::cross(State *prev, int n){
    State *s = new State(n);
    s = prev;

    do{
        s->right[this->boat[items]] = !s->right[this->boat[items]];
        s->left[this->boat[items]] = !s->left[this->boat[items]];
        this->boat[items] = 0;
        this->items--;
    }while(items != 0);
    return s;
}