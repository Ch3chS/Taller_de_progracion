#include <iostream>
#include "State.h"

using namespace std;

class Stack {
    public:
        int top; // indice del tope
        State **stack; // arreglo de punteros a State
        int size; // tamaño del arreglo
        Stack(int size);
        ~Stack();
        void push(State *s);
        State* pop();
        bool search(State *s);
        bool isEmpty();
        void print();
};