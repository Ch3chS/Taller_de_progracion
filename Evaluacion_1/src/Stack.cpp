#include "Stack.h"

Stack::Stack(int size) {
    this->size = size;
    top = -1;
    stack = new State*[size]; // crea arreglo de tamaño size 
}

Stack::~Stack() {
    delete[] stack;
}

void Stack::push(State *s) {
    if (top < size-1) {
        top++;
        stack[top] = s;
    } else {
        cout << "Stack overflow" << endl;
        State **tmp = new State*[2*size];
        for (int i = 0; i < size; i++) {
            tmp[i] = stack[i];
        }
        delete[] stack;
        stack = tmp;
        this->size = 2*size;
        push(s);
    }
}

State* Stack::pop() {
    if (top >= 0) {
        State *s = stack[top];
        top--;
        return s;
    } else { // caso vacio
        cout << "Stack underflow" << endl;
        return nullptr;
    }
}

bool Stack::search(State *s) {
    bool equal = false;
    for (int i = 0; i <= top; i++) {
        equal = true;
        for (int j = 0; j < 4; j++) {
            if (stack[i]->left[j] != s->left[j] 
             || stack[i]->right[j] != s->right[j]) {
                cout << "i: " << i << " j: " << j << endl;
                equal = false;
                break;
            }
        }
        if (equal) {
            return true;
        }

    }
    return false;
}

bool Stack::isEmpty() {
    return top == -1;
}

void Stack::print() {
    for (int i = 0; i <= top; i++) {
        stack[i]->print();
    }
}