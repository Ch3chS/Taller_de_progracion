#include <iostream>
#include <SymbolicProcessor.h>
#include <dirent.h>
#include <vector>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]){
    
    // Crear una instancia de SymbolicProcessor
    SymbolicProcessor processor;
    char opcion;
    bool salir = false;
    vector<string> files; // Vector para almacenar los nombres de los archivos en la carpeta "misc"
    string fileName; // String para almacenar el nombre del archivo elegido por el usuario

    while (!salir){
        cout << "\n\n---- Menú ----\n" << endl;
        cout << "1. Listar archivos" << endl;
        cout << "2. Evaluar expresión" << endl;
        cout << "3. Salir\n" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion){
            case '1':
                // En caso de que se seleccione esta opción se mostrarán los archivos en el directorio ./misc para que el usuario pueda elegir uno y este se cargue:

                DIR *dir; // Puntero a la estructura DIR para leer el contenido de un directorio
                struct dirent *ent; // Puntero a la estructura dirent para almacenar información sobre un archivo en el directorio
                if ((dir = opendir ("./misc")) != NULL) { // Abrir el directorio "misc"
                    int i = 1;
                    while ((ent = readdir (dir)) != NULL) { // Leer cada archivo en el directorio
                        if(strcmp(ent->d_name,".") != 0 && strcmp(ent->d_name,"..") != 0){ // Ignorar los archivos "." y ".."
                            cout << i << ". " << ent->d_name << endl; // Mostrar el nombre del archivo
                            files.push_back(ent->d_name); // Agregar el nombre del archivo al vector de archivos
                            i++;
                        }
                    }
                    closedir (dir); // Cerrar el directorio
                } else {
                    perror ("No se pudo abrir la carpeta"); // Mostrar un mensaje de error si no se pudo abrir el directorio (no debería pasar pero por si acaso)
                    break;
                }
                int fileIndex; // Variable para almacenar el índice del archivo elegido por el usuario
                cout << "\nIngrese el número del archivo que desea cargar: ";
                cin >> fileIndex; // Leer el índice del archivo elegido por el usuario
                fileName = "./misc/" + files[fileIndex-1]; // Obtener el nombre del archivo elegido por el usuario
                cout << "\nCargando " << fileName << "...\n" << endl;
                if (processor.load(fileName)) { // Cargar el archivo elegido por el usuario
                    std::cout << "Cargado!\n\n";
                    //Para acceder al arbol se usa processor.source()  (Es un recordatorio para mi XD por si vuelvo a trabajar en esto dias despues)
                }
                break;
            case '2':
                cout << "Evaluando...\n" << endl;
                break;
            case '3':
                salir = true; // Salir del programa
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n" << endl; // Mostrar un mensaje de error si la opción ingresada por el usuario no es válida
                break;
        }

    }
    

    return 0;
}