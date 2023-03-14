#include <iostream>
#include <fstream>
using namespace std;


int leer_archivo(){
    string nombre = "rio.txt";
    ifstream archivo(nombre.c_str());
    string linea;

    // Datos en general
    int datos[3];

    for(int i = 0; i<2; i++){
        getline(archivo,linea,' ');
        datos[i] = stoi(linea);
    }
    getline(archivo,linea);
    datos[2] = stoi(linea);


    // Restricciones //
    int r;

    // Restricciones izquierda
    getline(archivo,linea);
    r = stoi(linea);
    string r_left[r];

    for(int i = 0; i<r; i++){
        getline(archivo, linea);
        r_left[i] = linea;
    }
    
    for(int i = 0; i<r; i++){
        cout << r_left[i] << endl;
    }

    // Restricciones derecha
    getline(archivo,linea);
    r = stoi(linea);
    string r_right[r];

    for(int i = 0; i<r; i++){
        getline(archivo, linea);
        r_right[i] = linea;
    }
    
    for(int i = 0; i<r; i++){
        cout << r_right[i] << endl;
    }
    
    return 0;
}

// Procesarmiento e impresion

int main(int argc, char const *argv[]){
    
    leer_archivo();

    return 0;
}

