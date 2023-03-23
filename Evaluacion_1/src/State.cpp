#include "State.h"

State::State() {
    for (int i = 0; i < 4; i++) {
        left[i] = 1; // todos a la izquierda
        right[i] = 0; // nada a la derecha
    }
    previous = nullptr;
}

State::State(int left[], int right[], State* previous) {
    for (int i = 0; i < 4; i++) {
        this->left[i] = left[i];
        this->right[i] = right[i];
    }
    this->previous = previous;
}

State::~State() {
    // no se necesita
}

void State::print() {
    cout << "Izquierda: ";
    for (int i = 0; i < 4; i++) {
        cout << left[i] << " ";
    }
    cout << endl;
    cout << "Derecha: ";
    for (int i = 0; i < 4; i++) {
        cout << right[i] << " ";
    }
    cout << endl;
}

// asumimos que no hay contradicciones 
bool State::isFinal() {
    for (int i = 0; i < 4; i++) {
        if (right[i] == 0) {
            return false;
        }
    }
    return true;
}

void State::printPath() {
    State *actual = this; // this es puntero al objeto actual
    actual->print();
    while (actual->previous != nullptr) {
        actual = actual->previous;
        actual->print();
    }
}