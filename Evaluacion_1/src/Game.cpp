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


void Game::solve(){
    State *inicial = new State(this->n); // new llama al constructor y entrega un puntero
    open->push(inicial);
    Boat *boat = new Boat(this->boat);

    while (!open->isEmpty()) {
        // ---------------------------------------------- Cruce a la derecha ----------------------------------------------------------------------------
        State *s = open->pop();

        int i = 1;                    //LLenado de bote (en izquierda)
        boat->addItem(0);
        while(!boat->isFull() && i < this->n){
            if(canMoveL(s, i)){      // Se revisa si el item se puede mover
                boat->addItem(i);    //se agrega el item al bote
                i++;
            }
        }
        
        State *s1 = boat->cross(s, this->n);

        if(!closed->search(s1) && !open->search(s1)) open->push(s1);   // Si el estado no ha sido visitado lo pusheamos por visitar
            
        closed->push(s);
    
        // ---------------------------------------------- Se verifica final -----------------------------------------------------------------------------
        if (s1->isFinal(this->n)) {
            cout << "Solucion encontrada" << endl;
            s1->printPath(this->n);
            return;
        }
        open->push(s1);


        // -------------------------------------------- Cruce a la izquierda ----------------------------------------------------------------------------
        State *s2 = open->pop();

            // Se revisa si el item se puede mover

            //se agrega el item el item boat()

        // Despues de hacerlo con cada item recomendado (Con el bote a maxima capacidad de ser posible)

        State *s3 = boat->cross(s2, this->n);
        closed->push(s3);
    }
    cout << "No hay solucion" << endl;
    
}

State* Game::move(State *s, int item) {
    return s;
}


bool Game::canMoveL(State *s, int item) {
    bool find = true;                           // Esto nos dirá si se encontro una restricción igual a la del estado con este item77'?????????????????????DSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSST&/[ZiIi ]

    for(int i = 0; i < this->rleft->restrictionsNumber; i++){
        if(!this->rleft->restrictions[i][item]){             // Si el item a mover no se encuentra en la restriccion entonces no es necesario revisarla
        printf("\nCoord: (%d, %d)", i, item);
            for(int j = 0; j < this->rleft->n; j++){
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
    return true;        // Si se revisaron todas las restricciones y no son iguales al estado, entonces este es valido
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