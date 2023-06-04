#include "OperationNode.h"

/*
    * Método: Constructor->OperationNode
    * Descripción: Crea un nodo operación a partir de un carácter y punteros a sus 2 hijos
    * Parámetros:
    * - operation: un carácter con el contenido a asignarle a nodo
    * - left: puntero al hijo izquierdo del nodo operación
    * - right: puntero al hijo derecho del nodo operación
    * Retorno:
    * - void
*/
OperationNode::OperationNode(char operation, Node* left, Node* right){
    this->operation = operation;
    this->left = left;
    this->right = right;
    setType(OPERATOR);
}

/*
    * Método: Constructor->OperationNode
    * Descripción: Crea un nodo operación a partir de un carácter y 2 punteros a null (se usa si aún no se conocen sus hijos)
    * Parámetros:
    * - operation: un carácter con el contenido a asignarle a nodo
    * Retorno:
    * - void
*/
OperationNode::OperationNode(char operation) {
    this->operation = operation;
    left = nullptr;
    right = nullptr;
    setType(OPERATOR);
}

/*
    * Método: Destructor->OperationNode
    * Descripción: Elimina un objeto de tipo OperationNode
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
OperationNode::~OperationNode() {
    if (left != nullptr) {
        delete left;
    }
    
    if (right != nullptr) { 
        delete right;
    }
}

/*
    * Método: getOperation()
    * Descripción: Adquiere la operación almacenada en el OperationNode
    * Parámetros:
    * - void
    * Retorno:
    * - operation: un carácter con la operación del OperationNode
*/
char OperationNode::getOperation() const {
    return operation;
}

/*
    * Método: getLeft()
    * Descripción: Adquiere el puntero al hijo izquierdo del OperationNode
    * Parámetros:
    * - void
    * Retorno:
    * - left: un puntero que apunta al hijo izquierdo del OperationNode
*/
Node* OperationNode::getLeft() const {
    return left;
}

/*
    * Método: getRight()
    * Descripción: Adquiere el puntero al hijo derecho del OperationNode
    * Parámetros:
    * - void
    * Retorno:
    * - right: un puntero que apunta al hijo derecho del OperationNode
*/
Node* OperationNode::getRight() const {
    return right;
}

/*
    * Método: setLeft()
    * Descripción: Cambia el puntero del hijo izquierdo en el OperationNode
    * Parámetros:
    * - left: puntero al nuevo hijo izquierdo
    * Retorno:
    * - void
*/
void OperationNode::setLeft(Node* left){
    this->left = left;
}

/*
    * Método: setRight()
    * Descripción: Cambia el puntero del hijo derecho en el OperationNode
    * Parámetros:
    * - right: puntero al nuevo hijo derecho
    * Retorno:
    * - void
*/
void OperationNode::setRight(Node* right){
    this->right = right;
}

/*
    * Método: printTree()
    * Descripción: Imprime la operación contenida en el OperationNode
    * Parámetros:
    * - void
    * Retorno:
    * - void
*/
void OperationNode::printTree(){
    std::cout << operation << " ";

    if (left != nullptr) {
        left->printTree();
    }

    if (right != nullptr) {
        right->printTree();
    }
}