#include <iostream>

class Restrictions{
    public:
        int items;
        bool allowed(int item1, int item2);
        void addRestriction(int r1, int r2);
        Restrictions(int items);
        void print();

    private:
        bool **restrictions;    // Matriz dinamica con las restricciones
        int order_of_evaluate[];   // orden en el que se evaluan los items
};