#include "VariableNode.h"

/*
    * Método: Constructor->VariableNode
    * Descripción: Crea un nodo variable a partir de un string dado
    * Parámetros:
    * - variable: un string con el contenido a asignarle a nodo
    * Retorno:
    * - void
*/
VariableNode::VariableNode(const string& variable){
    this->variable = variable;
    this->setType(VARIABLE);
}

/*
    * Método: Destructor->VariableNode
    * Descripción: Elimina un objeto de tipo VariableNode
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
VariableNode::~VariableNode() {

}
    
/*
    * Método: getVariable()
    * Descripción: Adquiere la variable almacenada en el VariableNode
    * Parámetros:
    * - void
    * Retorno:
    * - variable: un string con la variable del nodo
*/
string VariableNode::getVariable() const{
    return variable;
}

/*
    * Método: setVariable()
    * Descripción: Cambia la variable almacenada en el VariableNode
    * Parámetros:
    * - variable: string con la variable a insertar en el nodo
    * Retorno:
    * - void
*/
void VariableNode::setVariable(const string& variable) {
    this->variable = variable;
}

/*
    * Método: printTree()
    * Descripción: Imprime la variable contenida en el VariableNode
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
void VariableNode::printTree() {
    cout << variable << " ";
}
