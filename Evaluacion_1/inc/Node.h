#include <iostream>
/*
Aqui declaramos las interfaces
*/

class Node { // esto es una declaracion abstracta sin implementacion
    public:
        int izq[4];
        int der[4];
        Node *previo;
        Node(int i[], int d[], Node* p); // constructor
        ~Node(); // destructor
        void print(); // imprime el nodo
        void printAll(); // imprime todos los previos
};