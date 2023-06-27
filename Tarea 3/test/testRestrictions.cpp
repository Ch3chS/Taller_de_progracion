#include "Restrictions.h"

int main(){
    string line;
    stringstream ss;
    Restrictions *restrictions1 = new Restrictions(1);
    Restrictions *restrictions2 = new Restrictions(2);
    Restrictions *restrictions3 = new Restrictions(3);
    vector<vector<float>> test;

    // Rellenando restricciones de tipo 1
    line = "1 2 3 4 5";
    ss << line;
    restrictions1->addRestriction(ss);
    ss.clear();
    line = "3 2 3 4 3";
    ss << line;
    restrictions1->addRestriction(ss);
    ss.clear();

    // Rellenando restricciones de tipo 2
    line = "5 4 3 2 1";
    ss << line;
    restrictions2->addRestriction(ss);
    ss.clear();
    line = "5 1 4 2 3";
    ss << line;
    restrictions2->addRestriction(ss);
    ss.clear();

    // Rellenando restricciones de tipo 3
    line = "1 5 2 4 3";
    ss << line;
    restrictions3->addRestriction(ss);
    ss.clear();
    
    // Concatenando restricciones en una matriz general
    test = restrictions1->concatenateRestrictions(restrictions1->getRestrictions(), restrictions2->getRestrictions(), restrictions3->getRestrictions());

    // Imprimiendo resultado para comprobar
    for(int i = 0; i < (int)test.size(); i++){
        for(int j = 0; j < (int)test.at(i).size(); j++){
            cout << test.at(i).at(j) << " ";
        }
        cout << "\n";
    }

    // Restriccion extra de tipo 2
    line = "2 2 2 2 2";
    ss << line;
    restrictions2->addRestriction(ss);
    ss.clear();

    // Restriccion extra de tipo 1
    line = "1 1 1 1 1";
    ss << line;
    restrictions1->addRestriction(ss);
    ss.clear();

    // Concatenando restricciones en una matriz general
    test = restrictions1->concatenateRestrictions(restrictions1->getRestrictions(), restrictions2->getRestrictions(), restrictions3->getRestrictions());

    // Imprimiendo resultado para comprobar
    cout << "\n\n";
    for(int i = 0; i < (int)test.size(); i++){
        for(int j = 0; j < (int)test.at(i).size(); j++){
            cout << test.at(i).at(j) << " ";
        }
        cout << "\n";
    }

    return 0;
}