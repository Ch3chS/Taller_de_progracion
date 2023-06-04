#include "Node.h"

/*
    * Método: Constructor->Node
    * Descripción: Crea un nodo
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
Node::Node() {
    type = INVALID; // Si se crea un nodo con este constructor es que no es ninguno de los 3 anteriores, por lo que es inválido
}

/*
    * Método: Destructor->Node
    * Descripción: Elimina un objeto de tipo Node
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
Node::~Node() {
}

/*
    * Método: getType()
    * Descripción: Adquiere el tipo de nodo, pudiendo ser NUMBER, OPERATOR, VARIABLE o INVALID 
    * Parámetros:
    * - void
    * Retorno:
    * - type: un entero con el tipo de nodo (ver los números asignados a cada tipo en Node.h)
*/
int Node::getType(){
    return type;
}

/*
    * Método: setType()
    * Descripción: Cambia el tipo del nodo
    * Parámetros:
    * - type: entero con el nuevo tipo del nodo
    * Retorno:
    * - void
*/
void Node::setType(int type){
    this->type = type;
}

/*
    * Método: printTree()
    * Descripción: No imprime nada realmente, ya que si se usa el método de esta superclase es porque el nodo es inválido (override en subclases)
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
void Node::printTree(){
    
}