#include "NumberNode.h"

/*
    * Método: Constructor->NumberNode
    * Descripción: Crea un nodo número a partir de un entero dado
    * Parámetros:
    * - value: un entero con el contenido a asignarle al nodo
    * Retorno:
    * - void
*/
NumberNode::NumberNode(int value){
    this->value = value;
    setType(NUMBER);
}

/*
    * Método: Destructor->NumberNode
    * Descripción: Elimina un objeto de tipo NumberNode
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
NumberNode::~NumberNode(){

}

/*
    * Método:
    * Descripción:
    * Parámetros:
    * - void
    * Retorno:
    * - value: un entero con el número del nodo
*/
int NumberNode::getValue() const {
    return value;
}

/*
    * Método: printTree()
    * Descripción: Imprime el entero contenido en el NumberNode
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
void NumberNode::printTree() {
    cout << value << " ";
}
