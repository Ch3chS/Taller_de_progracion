#include "Node.h"

int Node::getN(){
    return this->N;
}

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
    ss >> this->N >> this->m1 >> this->m2 >> this->m3;


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
    cout << "hola\n";
    return s->solve();
}

vector<float> Node::solve(){
    if(this->enteros.size() == 0){
        this->simplex();
    }
    
    vector<float> a;

    return a;
}


void Node::printMatriz(vector<vector<float>> m){
    for(int i = 0; i < (int)m.size(); i++){
        for(int j = 0; j < (int)m.at(i).size(); j++){
            cout << m.at(i).at(j) << " ";
        }
        cout << "\n";
    }
}