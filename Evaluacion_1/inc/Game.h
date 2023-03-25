#include <iostream>
#include "Stack.h"

using namespace std;

// clase que representa el problema  del Lobo-Cabra-Repollo
class Game {
    public:
        Stack *open;
        Stack *closed;
        Game();
        ~Game();
        void solve(); // resuelve el problema
        State* moveL(State *s); // mueve el lobo
        State* moveG(State *s); // mueve el granjero solo
        State* moveC(State *s); // mueve la cabra
        State* moveR(State *s); // mueve el repollo
        bool canMoveL(State *s); // verifica si se puede mover el lobo
        bool canMoveG(State *s); // verifica si se puede mover el granjero solo
        bool canMoveC(State *s); // verifica si se puede mover la cabra
        bool canMoveR(State *s); // verifica si se puede mover el repollo
};