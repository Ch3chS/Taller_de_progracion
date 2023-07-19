#include "Node.h"

int Node::getM1(){
    return this->m1;
}

int Node::getM2(){
    return this->m2;
}

int Node::getM3(){
    return this->m3;
}

vector<int> Node::getEnteros(){
    return enteros;
}

vector<float> Node::getCoef(){
    return coeficientes_f;
}

vector<vector<float>> Node::getRestrictions(){
    return this->restrictions_m1->concatenateRestrictions(restrictions_m1->getRestrictions(), restrictions_m2->getRestrictions(), restrictions_m3->getRestrictions());
}


bool Node::load(string filename) {

    ifstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    this -> m1 = 0;
    this -> m2 = 0;
    this -> m3 = 0;

    string line;
    stringstream ss;
    int temp;
    float temp2;


    restrictions_m1 = new Restrictions(1); // Inicializar restrictions_m1 como una instancia de Restrictions
    restrictions_m2 = new Restrictions(2); // Inicializar restrictions_m2 como una instancia de Restrictions
    restrictions_m3 = new Restrictions(3); // Inicializar restrictions_m3 como una instancia de Restrictions


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
    

    // Carga de la tercera linea (Coeficientes de función objetivo)
    this->coeficientes_f.clear();
    getline(file, line);
    ss.clear();
    ss << line;
    while(ss >> temp2){
        this->coeficientes_f.push_back(temp2);    // Se agregan los coeficientes al vector con los enteros
    }

    // Carga de las restricciones de tipo 1 (Restricciones del tipo <=)
    for(int i = 0; i < this->m1; i++){
        getline(file, line);
        ss.clear();
        ss << line;

        restrictions_m1->addRestriction(ss);
    }

    // Carga de las restricciones de tipo 2 (Restricciones del tipo >=)
    for(int i = 0; i < this->m2; i++){
        getline(file, line);
        ss.clear();
        ss << line;
        restrictions_m2->addRestriction(ss);
    }


    // Carga de las restricciones de tipo 3 (Restricciones del tipo ==)
    for(int i = 0; i < this->m3; i++){
        getline(file, line);
        ss.clear();
        ss << line;
        restrictions_m3->addRestriction(ss);
    }

    return true;
}

vector<float> Node::simplex(){
    Simplex *s = new Simplex(this->getRestrictions(), this->getM1(), this->getM2(), this->getM3());
    vector<float> solution = s->solve();
    if((int)solution.size() == 0) solution.push_back(0);
    return solution;
}

Node *Node::copy(){
    Node* node = new Node();
    node->m1 = this->m1;
    node->m2 = this->m2;
    node->m3 = this->m3;
    node->enteros = this->enteros;
    node->coeficientes_f = this->coeficientes_f;
    node->restrictions_m1 = this->restrictions_m1;
    node->restrictions_m2 = this->restrictions_m2;
    node->restrictions_m3 = this->restrictions_m3;
    return node;
}

vector<float> Node::solve() {
    vector<float> node_solution = this->simplex();

    // Un vector con un solo 0 indica que no hay solución
    if((int)node_solution.size() == 1)  return node_solution;

    // Caso base, si ya no quedan más restricciones de entero se retorna la solución actual
    if (this->enteros.empty()) {
        return node_solution;
    }


    // De quedar restricciones de entero por revisar se va desde el final del vector al principio
    int indice = enteros.back(); // Indice de la variable entera
    enteros.pop_back();
    int r1 = int(node_solution.at(indice + 1));   // variable -> variable <= r1
    cout << "chao\n";
    int r2 = r1 + 1;                              // variable -> variable >= r2
    
    // Ramifico la incognita del indice para ambos lados con sus respectivos enteros
    left = copy();  
    Simplex *s1 = new Simplex(left->getRestrictions(), left->getM1(), left->getM2(), left->getM3());
    s1->insertConstraint(r1, indice + 1, 1);

    right = copy();
    Simplex *s2 = new Simplex(right->getRestrictions(), right->getM1(), right->getM2(), right->getM3());
    s2->insertConstraint(r2, indice + 1, 2);

    // Resuelvo cada uno de los lados
    vector<float> left_solution = s1->solve();
    vector<float> right_solution = s2->solve();

    //Elijo la rama con mayor Z y prosigo
    if((int)left_solution.size() == 0) left_solution.push_back(0);   // Para evitar problemas de vector vacio en lo siguiente verificamos
    if((int)right_solution.size() == 0) right_solution.push_back(0);

    if(left_solution.at(0) > right_solution.at(0)){
        return left->solve();
    }
    else{
        return right->solve();
    }
}



void Node::printMatriz(vector<vector<float>> m){
    for(int i = 0; i < (int)m.size(); i++){
        for(int j = 0; j < (int)m.at(i).size(); j++){
            cout << m.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}