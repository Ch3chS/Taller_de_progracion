#include <iostream>
#include <fstream>
#include "../inc/State.h"
#include "../inc/Restrictions.h"

using namespace std;

// Procesarmiento e impresion
int main(int argc, char const *argv[]){
    
    if(argc < 2){
        printf("\nDebe ingresar el nombre del archivo\n\n");
        return 1;
    }

    int drivers, items, boat;

    // --------------------------------------- Carga de datos ----------------------------------------------------------

    // Abriendo archivo
    string nombre = "./misc/";
    nombre.append(argv[1]);
    ifstream archivo(nombre.c_str());
    string linea;

    if(!archivo.is_open()){
        printf("\nNo se pudo abrir el archivo.\n\n");
        return 1;
    }
    
    // Datos principales
    getline(archivo,linea,' ');
    drivers = stoi(linea);
    getline(archivo,linea,' ');
    items = stoi(linea);
    getline(archivo,linea);
    boat = stoi(linea);


    // --- Carga de restricciones ---
    int r1, r2;
    r1 = boat;
    // Izquierda
    Restrictions *leftRestrictions;
    leftRestrictions = new Restrictions(items);

    getline(archivo,linea);
    int r = stoi(linea);

    for(int i = 0; i<r; i++){
        getline(archivo, linea, ' ');
        r1 = stoi(linea) - 1 - drivers;
        getline(archivo, linea);
        r2 = stoi(linea) - 1 - drivers;
        leftRestrictions->addRestriction(r1, r2);
    }

    // Derecha
    Restrictions *rightRestrictions;
    rightRestrictions = new Restrictions(items);

    getline(archivo,linea);
    r = stoi(linea);

    for(int i = 0; i<r; i++){
        getline(archivo, linea, ' ');
        r1 = stoi(linea) - 1 - drivers;
        getline(archivo, linea);
        r2 = stoi(linea) - 1 - drivers;
        rightRestrictions->addRestriction(r1, r2);
    }

    archivo.close();


    // --------------------------------------- Procesamiento ----------------------------------------------------------
    /*

    // Estado inicial
    int izq[drivers + items];
    int der[drivers + items];

    Node *initial;
    initial = new Node(izq, der, NULL);


nodo con menor distancia al estado final o a la diagonal

buscar en visitados, (busqueda binaria, se pueden ordenar)
get, por visitar (heap o cola de prioridad)

tabla de hash

estado inicial = (GLCR,0000)
estado final = (0000,GLCR)

    */

    return 0;
}

