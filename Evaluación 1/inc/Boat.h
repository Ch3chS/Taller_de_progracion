#include <iostream>
#include "State.h"

using namespace std;

class Boat{
    public:
        int size;
        int items;
        int *boat;

        Boat(int size);
        ~Boat();
        bool isFull();
        void addItem(int item);
        State *cross(State *prev, int n);
};