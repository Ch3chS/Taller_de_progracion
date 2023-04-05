#include <iostream>

class Restrictions{
    public:
        int n, restrictionsNumber;
        bool **restrictions;    // Matriz dinamica con las restricciones
        bool allowed(int item1, int item2);
        void addRestriction(int r1, int r2);
        Restrictions(int n, int restrictions);
        void print();
        int getn();

    private:
        int order_of_evaluate[];   // orden en el que se evaluan los items
};