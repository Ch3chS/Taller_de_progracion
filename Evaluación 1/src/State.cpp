#include "State.h"

State::State(int n) {
        this->n = n;
        this->left = new bool[n];
        this->right = new bool[n];
    for (int i = 0; i < n; i++) {
        this->left[i] = true;
        this->right[i] = false;
    }
    previous = nullptr;
}

State::State(bool *left, bool *right, State* previous, int n){
    this->n = n;
    this->left = left;
    this->right = right;
    this->previous = previous;
}

State::~State() {
    // no se necesita
}

void State::print(int n) {
    cout << "Izquierda: ";
    for (int i = 0; i < n; i++) {
        cout << left[i] << " ";
    }
    cout << endl;
    cout << "Derecha: ";
    for (int i = 0; i < n; i++) {
        cout << right[i] << " ";
    }
    cout << endl;
}

// asumimos que no hay contradicciones 
bool State::isFinal(int n) {
    for (int i = 0; i < n; i++) {
        if (right[i] == false) {
            return false;
        }
    }
    return true;
}

void State::printPath(int n) {
    State *actual = this; // this es puntero al objeto actual
    actual->print(n);
    while (actual->previous != nullptr) {
        actual = actual->previous;
        actual->print(n);
    }
}