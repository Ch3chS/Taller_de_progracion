#include <iostream>
#include <fstream>
#include "../inc/Game.h"

using namespace std;


int main(int argc, char const *argv[]){
    
    if(argc < 2){
        printf("\nDebe ingresar el nombre del archivo\n\n");   // Por si no se ingreso el nombre del archivo
        return 1;
    }

    Game *game = new Game();                             // Se crea un juego

    string name = "./misc/";
    name.append(argv[1]);                              // Se completa el nombre del archivo con la ruta de archivos

    int failed = game->load(name);                     // Se cargan los datos del archivo

    if(failed == 1 ){
        delete game;
        printf("\nNo se pudo abrir el archivo.\n\n");    // En caso de que no se haya podido leer el archivo se avisa por consola y termina el programa
        return 1;
    }

    game->solve();                                       // Se resuelve
   
    delete game;
    return 0;
}

