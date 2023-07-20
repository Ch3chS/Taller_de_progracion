#include "Node.h"

// ----------------------------------------------------------- Constructores -----------------------------------------------------------------

/*
    * Método: Constructor->Node
    * Descripción: Crea un nodo
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
Node::Node() {
    this->upperBound = 0;
    this->lowerBound = 0;
    this->right = nullptr;
    this->left = nullptr;
}

/*
    * Método: Constructor->Node
    * Descripción: Crea un nodo a partir de su upperBound y lowerBound
    * Parámetros:
    * - upperBound: Flotante con el valor de la cota superior del sub-problema
    * - lowerBound: Flotante con el valor de la cota inferior del sub-problema
    * Retorno:
    * - void
*/
Node::Node(float upperBound, float lowerBound) {
    this->setUpperBound(upperBound);
    this->setLowerBound(lowerBound);
    this->right = nullptr;
    this->left = nullptr;
}


// -------------------------------------------------------------- Getters --------------------------------------------------------------------

/*
    * Método: getUpperBound
    * Descripción: Getter que retorna el upperBound del nodo
    * Parámetros:
    * - void
    * Retorno:
    * - upperBound: Flotante con el valor de la cota superior del sub-problema
*/
float Node::getUpperBound() {
    return this->upperBound;
}

/*
    * Método: getLowerBound
    * Descripción: Getter que retorna el lowerBound del nodo
    * Parámetros:
    * - void
    * Retorno:
    * - lowerBound: Flotante con el valor de la cota inferior del sub-problema
*/
float Node::getLowerBound() {
    return this->lowerBound;
}

/*
    * Método: getLeft
    * Descripción: Getter que retorna el hijo izquierdo del nodo
    * Parámetros:
    * - void
    * Retorno:
    * - left: Nodo hijo del lado izquierdo
*/
Node *Node::getLeft() {
    return this->left;
}

/*
    * Método: getRight
    * Descripción: Getter que retorna el hijo derecho del nodo
    * Parámetros:
    * - void
    * Retorno:
    * - left: Nodo hijo del lado derecho
*/
Node *Node::getRight() {
    return this->right;
}


// -------------------------------------------------------------- Setters --------------------------------------------------------------------

/*
    * Método: setUpperBound
    * Descripción:  Setter que reemplaza el upperBound del nodo
    * Parámetros:
    * - upperBound: Flotante con el valor de la cota superior del sub-problema
    * Retorno:
    * - void
*/
void Node::setUpperBound(float upperBound) {
    this->upperBound = upperBound;
}

/*
    * Método: setLowerBound
    * Descripción:  Setter que reemplaza el lowerBound del nodo
    * Parámetros:
    * - upperBound: Flotante con el valor de la cota inferior del sub-problema
    * Retorno:
    * - void
*/
void Node::setLowerBound(float lowerBound) {
    this->lowerBound = lowerBound;
}

/*
    * Método: setLowerBound
    * Descripción:  Setter que calcula y reemplaza el lowerBound del nodo haciendo uso de elementos
    * Parámetros:
    * - result: Vector de flotantes resultante del uso de simplex (Z, valores_de_las_variables)
    * - enteros: Vector de enteros con los indices de las variables que tienen restricción de valor entero
    * - coef: Vector de flotantes con los coeficientes de la función a maximizar
    * Retorno:
    * - void
*/
void Node::setLowerBound(vector<float> result, vector<int> enteros, vector<float> coef) {
    float lowerBound = 0;
    for(int i = 0; i < (int)enteros.size(); i++) {
        result.at(enteros.at(i)) = static_cast<int>(result.at(enteros.at(i)));
    }
    for(int i = 1; i < (int)result.size(); i++) {
        lowerBound += (result.at(i) * coef.at(i));
    }
    this->lowerBound = lowerBound;
}

/*
    * Método: setLeft
    * Descripción: Setter que reemplaza el hijo izquierdo del nodo
    * Parámetros:
    * - left: Nuevo nodo hijo del lado izquierdo
    * Retorno:
    * - void
*/
void Node::setLeft(Node *node) {
    this->left = node;
}

/*
    * Método: setRight
    * Descripción: Setter que reemplaza el hijo derecho del nodo
    * Parámetros:
    * - left: Nuevo nodo hijo del lado derecho
    * Retorno:
    * - void
*/
void Node::setRight(Node *node) {
    this->right = node;
}