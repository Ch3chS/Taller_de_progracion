#include "Node.h"

Node::Node(int izq[], int der[], Node* p) {
    for (int j = 0; j < 4; j++) {
        this->izq[j] = izq[j];
        this->der[j] = der[j];
    }
    // this : puntero al objeto actual
    // x->y == (*x).y
    // x.y : es el valor de y en el objeto x
    previo = p;
}

Node::~Node() {
    // destructor
}

// x[i] ==  *(x+i)

void Node::print() {
    for (int i = 0; i < 4; i++) {
        std::cout << izq[i] << " ";
    }
    std::cout << " | ";
    for (int i = 0; i < 4; i++) {
        std::cout << der[i] << " ";
    }  
    std::cout << std::endl;
}

void Node::printAll() {
    Node* p = this;
    while (p != nullptr) {
        p->print();
        p = p->previo;
    }
}