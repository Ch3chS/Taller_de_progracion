#include <iostream>

using namespace std;

class Boat{
    public:
        bool left;  // true = izquierda, false = derecha
        Boat();
        ~Boat();
        void addItem();
        void cross();
};