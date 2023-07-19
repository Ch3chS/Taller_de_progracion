#include <ctime>
#include <cstring>
#include <dirent.h>
#include "Node.h"

using namespace std;

int main(int argc, char const *argv[]) {
/*
    // Crear una instancia de SymbolicProcessor
    Node node;
    char opcion;
    string variable;
    bool exit = false;
    bool loaded = false;
    vector<float> result;
    vector<string> files; // Vector para almacenar los nombres de los archivos en la carpeta "misc"
    string fileName; // String para almacenar el nombre del archivo elegido por el usuario
    double time;
    unsigned t0, t1;

    while (!exit) {
        cout << "\n\n---- Menú ----\n" << endl;
        cout << "1. Listar archivos" << endl;
        cout << "2. Simplex" << endl;
        cout << "3. Branch and Bound" << endl;
        cout << "4. Salir\n" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            case '1':
                // En caso de que se seleccione esta opción se mostrarán los archivos en el directorio "./misc" para que el usuario pueda elegir uno y este se cargue:

                DIR *dir; // Puntero a la estructura DIR para leer el contenido de un directorio
                struct dirent *ent; // Puntero a la estructura dirent para almacenar información sobre un archivo en el directorio
                if ((dir = opendir ("./misc")) != NULL) { // Abrir el directorio "misc"
                    int i = 1;
                    cout << "\nArchivos en carpeta:\n" << endl;
                    while ((ent = readdir (dir)) != NULL) { // Leer cada archivo en el directorio
                        if(strcmp(ent->d_name,".") != 0 && strcmp(ent->d_name,"..") != 0) { // Ignorar los archivos "." y ".."
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
                cin >> fileIndex; // Leer el índice del archivo elegido por el usuario4
                fileName = "./misc/" + files[fileIndex - 1]; // Obtener el nombre del archivo elegido por el usuario
                cout << "\nCargando " << fileName << "...\n" << endl;
                
                t0 = clock();
                if (node.load(fileName)) { // Cargar el archivo elegido por el usuario
                    cout << "Cargado!\n\n";
                    //processor.getSource()->printTree();
                    loaded = true;
                }

                t1 = clock();
                time = (double(t1 - t0) / CLOCKS_PER_SEC);
                cout << "Tiempo de ejecución: " << time << "(s)" << endl;
                
                break;
            case '2':
                if(loaded){
                    t0 = clock();
                    result = node.simplex();
                    if((int)result.size() == 1){
                        cout << "No hay solución\n\n";
                        break;
                    }
                    for(int i = 0; i < (int)result.size(); i++){
                        cout << result.at(i) << " ";
                    }
                    cout << "\n\n";

                    t1 = clock();
                    time = (double(t1 - t0) / CLOCKS_PER_SEC);
                    cout << "Tiempo de ejecución: " << time << "(s)" << endl;
                }
                else{
                    cout << "\nPrimero debe cargar un archivo, intentelo denuevo\n";
                }
                break;
            case '3':
                if(loaded){
                    t0 = clock();
                    result = node.solve();
                    if((int)result.size() == 1){
                        cout << "No hay solución\n\n";
                        break;
                    }
                    for(int i = 0; i < (int)result.size(); i++){
                        cout << result.at(i) << " ";
                    }
                    cout << "\n\n";

                    t1 = clock();
                    time = (double(t1 - t0) / CLOCKS_PER_SEC);
                    cout << "Tiempo de ejecución: " << time << "(s)" << endl;
                }
                else{
                    cout << "\nPrimero debe cargar un archivo, intentelo denuevo\n";
                }
                break;  
            case '4':
                exit = true; // Salir del programa
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n" << endl; // Mostrar un mensaje de error si la opción ingresada por el usuario no es válida
                break;
        }
    }
    */
    return 0;
}
