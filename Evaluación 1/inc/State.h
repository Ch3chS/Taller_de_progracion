#ifndef STATE_H
#define STATE_H

#include <iostream>

using namespace std;

#define WOLF 0
#define GOAT 1
#define CABBAGE 2
#define FARMER 3

class State {
    public:
        int n;
        bool *left;      // Lista booleana
        bool *right;     // Lista booleana
        State* previous;
        State(int n); // constructor por fecto sin argumentos
        State(bool *left, bool *right, State* previous, int n); // constructores especificos
        ~State(); // destructor
        void print(int n); // imprime el estado
        bool isFinal(int n); // verifica si es el estado final
        void printPath(int n); // imprime el camino desde el estado inicial hasta el final
};

#endif // STATE_H