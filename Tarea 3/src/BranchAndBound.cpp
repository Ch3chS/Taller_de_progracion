#include "BranchAndBound.h"

BranchAndBound::BranchAndBound(string filename) {

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    this -> m1 = 0;
    this -> m2 = 0;
    this -> m3 = 0;

    string line, token;
    stringstream ss;
    int temp;
       

    // Carga de la primera linea (N: N°Variables, mi: Restricciones tipo i (i = 1, 2 o 3))
    getline(file, line);
    ss << line;
    ss >> this->m1 >> this->m2 >> this->m3;


    // Carga de la segunda linea (Indices de variable con restricción entera)
    this->enteros.clear();
    getline(file, line);
    ss.clear();
    ss << line;
    while(ss >> temp){
        this->enteros.push_back(temp);    // Se agregan los indices al vector
    }

    // leyendo la matrix que incluye c,a,b: (m+1) x (n+1), donde n es el numero de variables y m=m1+m2+m3 el numero de restricciones
    while (getline(file, line)) {
        ss.clear();
        ss << line;
        vector<float> row;
        while (getline(ss, token, ' '))
        {
            row.push_back(stof(token));
        }
        this->a.push_back(row);
    }
    this->n = a[0].size() - 1;
    this-> m = m1+ m2 + m3;

    // si hay una cantidad distinta de resticciones a las indicadas: Error!
    if (m != (int)a.size() - 1) {
        cout<<"Error en la cantidad de restricciones."<<endl;
        exit(1);
    }

    // si hay una cantidad distinta de variables a las indicadas: Error!
    for (int i = 1; i <= m; i++) {
        if (a[i][0] < 0.0 || (int)a[i].size() != n + 1){
            cout<<"Error en la cantidad de variables o constante menor que 0:" << i <<endl;
            exit(1);
        }
    }

    // EL metodo requiere una fila adicional al final de la matriz para calculos intermedios
    vector<float> row;
    for (int i = 0; i <= n; i++) {
        row.push_back(0.0);
    }

    this->a.push_back(row);
    this->isSolved = false; // inicialmente aún no se ha resuelto
    this->root = new Node();
    file.close();
}


vector<float> BranchAndBound::solve(){
    Simplex s = Simplex(this->a, this->m1, this->m2, this->m3);
    vector<float> result = s.solve();

    //Si no tiene solución
    if((int)result.size() == 0){
        return result;
    }

    this->root->setUpperBound(result[0]);
    // Si no quedan enteros por revisar entonces retornamos el resultado
    if(this->enteros.size() == 0){
        return result;
    }
}