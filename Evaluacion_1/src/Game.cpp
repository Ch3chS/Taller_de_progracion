#include <fstream>
#include <sstream>
#include "Game.h"

Game::Game() {
    open = new Stack(1000);
    closed= new Stack(1000);
}


Game::~Game() {
    delete open;
    delete closed;
}


void Game::solve() {
    State *inicial = new State(this->n); // new llama al constructor y entrega un puntero
    open->push(inicial);
    while (!open->isEmpty()) {
        State *s = open->pop();
        if (s->isFinal(this->n)) {
            cout << "Solucion encontrada" << endl;
            s->printPath(this->n);
            return;
        }
        closed->push(s);
        
        /*
        if(canMove){
            move(){

            }
            Si el creado no esta cerrado ni abierto entonces se agrega al stack, caso contrario se borra
        }
        */

    } // while
    cout << "No hay solucion" << endl;
}

State* Game::move(State *s, int item) {
    return s;
}


bool Game::canMoveL(State *s, int item) {
    bool find = true;
    for(int i = 0; this->rleft->restrictionsNumber; i++){
        if(!this->rleft->restrictions[i][item]){             // Si el item a mover no se encuentra en la restriccion entonces no es necesario revisarla
            for(int j = 0; this->rleft->n; j++){
                if(this->rleft->restrictions[i][j] != s->left[j]){
                    find = false;                            // Si la restriccion es 
                    break;
                }
            }
            if(find){
                return false;
            }
            find = true;
        }
    }
    return false;        // Si se revisaron todas las restricciones y no son iguales al estado, entonces este es valido
}

bool Game::canMoveR(State *s, int item) {
    bool find = true;
    for(int i = 0; this->rright->restrictionsNumber; i++){
        if(!this->rright->restrictions[i][item]){             // Si el item a mover no se encuentra en la restriccion entonces no es necesario revisarla
            for(int j = 0; this->rright->n; j++){
                if(this->rright->restrictions[i][j] != s->left[j]){
                    find = false;                            // Si la restriccion es 
                    break;
                }
            }
            if(find){
                return false;
            }
            find = true;
        }
    }
    return false;        // Si se revisaron todas las restricciones y no son iguales al estado, entonces este es valido
}



int Game::load(string fileName){
    ifstream *file = new ifstream(fileName); // abrir el archivo
    if (!file->is_open()) { // verificar que el archivo se abrio correctamente
        return 1;
    }

    string line; // linea de texto
    stringstream ss; // stream de caracteres


    // variables a leer del archivo

    // leer la primera linea
    getline(*file, line);
    ss << line; // copiar la linea al stream
    ss >> this->drivers >> this->items >> this->boat; // leer los datos del stream
    this->n = this->drivers + this->items;

    
    // leer las restricciones del lado izquierdo
    int rl;
    getline(*file, line);
    rl=atoi(line.c_str()) ; // c_str convierte el string a un arreglo de caracteres

    Restrictions *rleft = new Restrictions(this->n, rl);

    for (int i = 0; i < rl; i++) {

        getline(*file, line);
        ss.clear(); // NO OLVIDAR ESTO: limpiar el stream de caracteres, porque ya viene con cosas
        ss << line; // llenar el stream con linea
        while (!ss.eof()) { // mientras no termine esta linea
            int a;
            ss >> a;
            rleft->addRestriction(i, a-1);
        }
    }

    this->rleft = rleft;
    
    
    // leer las restricciones del lado derecho
    int rr;
    getline(*file, line);
    rr=atoi(line.c_str()) ; // c_str convierte el string a un arreglo de caracteres

    Restrictions *rright = new Restrictions(this->n, rr);

    for (int i = 0; i < rr; i++) {

        getline(*file, line);
        ss.clear(); // NO OLVIDAR ESTO: limpiar el stream de caracteres, porque ya viene con cosas
        ss << line; // llenar el stream con linea
        while (!ss.eof()) { // mientras no termine esta linea
            int a;
            ss >> a;
            rright->addRestriction(i, a-1);
        }
    }

    this->rright = rright;
    
    return 0;
}