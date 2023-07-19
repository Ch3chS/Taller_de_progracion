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
    this->simplex = new Simplex(this->a, this->m1, this->m2, this->m3);
    file.close();
}


bool BranchAndBound::isFeasible(vector<float> result) {
    return (int)result.size() != 0;
}

bool BranchAndBound::isSolution(Node *node) {
    return fabs(node->getLowerBound() - node->getUpperBound()) < 0.001;
}

int BranchAndBound::selectIndex(vector<float> result){
    float max = 0;
    int index = 0;
    float temp = 0;
    for(int i = 0; i < (int)enteros.size(); i++){
        temp = result.at(enteros.at(i)) - (int)result.at(enteros.at(i));
        if(temp > max){
            max = temp;
            index = enteros.at(i);
        } 
    }
    return index;
}

void BranchAndBound::solve() {
    vector<float> result = solve(this->root, this->simplex);
    if(!isFeasible(result)){
        cout << "No tiene solución.\n\n";
    }
    else{
        cout << "La solución es: \n";
        for(int i = 0; i < (int)result.size(); i++){
            cout << result.at(i) << " ";
        }
        cout << "\n\n";
    }
}

vector<float> BranchAndBound::solve(Node *node, Simplex *s){
    vector<float> result = s->solve();

    //Si no tiene solución se retorna el vector vacio (No seguimos por aqui (podamos))
    if(!isFeasible(result)){
        return result;
    }
    
    // Almacenamos el upperBound y lowerBound de este nodo
    node->setUpperBound(result[0]);
    node->setLowerBound(result, this->enteros, a[0]);

    // Si es solución (upperBound = lowerBound) la retornamos
    if(isSolution(node)){ 
        return result;
    }
    
    // ----------------------------- Si no es solución ramificamos -------------------------------------------
    // Copiamos simplex
    Simplex *sleft = s->copy2();
    Simplex *sright = s->copy2();

    // Elegimos variable para agregar restricciones
    int index = selectIndex(result);

    // Obtenemos valor entero de la variable elegida (truncada)
    int temp = (int)result.at(index);

    // Insertamos restricciones para cada uno de los lados
    sleft->insertConstraint(temp, index, 1);
    sright->insertConstraint(temp + 1, index, 2);


    // Creamos los nodos a usar
    node->setLeft(new Node());
    node->setRight(new Node());

    // Realizamos los llamados recursivos respectivos
    vector<float> leftResult = solve(node->getLeft(), sleft);
    vector<float> rightResult = solve(node->getRight(), sright);

    // ---------------------------------- Evaluación de resultados -------------------------------------------------------------
    // Si ambos son factibles comparamos
    if(isFeasible(leftResult) && isFeasible(rightResult)){
        if(leftResult.at(0) > rightResult.at(0)) return leftResult;
        return rightResult;
    }
    // Si solo uno es factible retornamos ese
    if(isFeasible(leftResult)) return leftResult;
    if(isFeasible(rightResult)) return rightResult;
    // Si ninguno es factible retornamos cualquiera de los 2 (es un vector vacio)
    return rightResult;
}