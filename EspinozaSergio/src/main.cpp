#include <vector>
#include <cstring>
#include "dirent.h"
#include "SymbolicProcessor.h"

int main(int argc, char const *argv[]) {

    // Crear una instancia de SymbolicProcessor
    SymbolicProcessor processor;
    char opcion;
    string variable;
    bool exit = false;
    bool loaded = false;
    vector<string> files; // Vector para almacenar los nombres de los archivos en la carpeta "misc"
    string fileName; // String para almacenar el nombre del archivo elegido por el usuario

    while (!exit) {
        cout << "\n\n---- Menú ----\n" << endl;
        cout << "1. Listar archivos" << endl;
        cout << "2. Derivar expresión" << endl;
        cout << "3. Simplificar expresión" << endl;
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
                if (processor.load(fileName)) { // Cargar el archivo elegido por el usuario
                    cout << "Cargado!\n\n";
                    processor.getSource()->printTree();
                    // Para acceder al árbol se usa processor.source()  (Es un recordatorio para mí XD por si vuelvo a trabajar en esto días después)
                    loaded = true;
                }
                break;
            case '2':
                if (loaded) {
                    cout << "Ingrese la variable con respecto a la cual derivar: ";
                    cin >> variable;
                    cout << "\nDerivando...\n" << endl;
                    processor.setSource(processor.deriveExpression(processor.getSource(), variable));
                    processor.getSource()->printTree();  
                } 
                else {
                    cout << "Primero debe cargar un archivo (opción 1)\n" << endl;
                }
                
                break;
            case '3':
                if (loaded) {
                    cout << "Simplificando...\n" << endl;
                    processor.setSource(processor.simplifyExpression(processor.getSource()));
                    processor.getSource()->printTree();
                } 
                else {
                    cout << "Primero debe cargar un archivo (opción 1)\n" << endl;
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

    return 0;
}
