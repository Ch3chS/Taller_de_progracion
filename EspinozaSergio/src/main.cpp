#include <iostream>
#include <OperationNode.h>
#include <Node.h>
using namespace std;

int main(int argc, char const *argv[]){
    
    char opcion;
    bool salir = false;

    while (!salir){
        cout << "\n---- Menú ----\n" << endl;
        cout << "1. Listar archivos" << endl;
        cout << "2. Evaluar expresión" << endl;
        cout << "3. Salir\n" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion){
            case '1':
                cout << "Cargando...\n" << endl;
                break;
            case '2':
                cout << "Evaluando...\n" << endl;
                break;
            case '3':
                salir = true;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n" << endl;
                break;
        }

    }
    

    return 0;
}