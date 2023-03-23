#include <iostream>
#include <unordered_map>
#include "State.h"
#include "Restrictions.h"

using namespace std;

class Game{
    public:
        int getItems();
        void solve();
        void visitState(State *s);
        bool canMove(State *s, int item);
    private:
        int drivers;
        int items;
        int n;
        Restrictions rLeft;
        Restrictions rRight;
        unordered_map<string, bool[]> visitedStates;

};