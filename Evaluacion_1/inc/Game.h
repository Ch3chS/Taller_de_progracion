#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Stack.h"
#include "Restrictions.h"
#include "Boat.h"

using namespace std;

// clase que representa el problema  del Lobo-Cabra-Repollo
class Game {
    public:
        Stack *open;
        Stack *closed;
        Game();
        ~Game();
        int load(string fileName);
        void solve(); // resuelve el problema
        State* move(State *s, int item);
        bool canMoveL(State *s, int item);
        bool canMoveR(State *s, int item);

    private:
        int items;
        int drivers;
        int boat;
        int n;
        Restrictions *rright;
        Restrictions *rleft;
};

#endif // GAME_H