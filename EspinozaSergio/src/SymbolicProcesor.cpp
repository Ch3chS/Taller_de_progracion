#include "SymbolicProcessor.h"
#include "OperationNode.h"
#include "NumberNode.h"
#include "VariableNode.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;

Node* SymbolicProcessor::getSource(){
    return this->source;
}

bool SymbolicProcessor::load(string filename) {
    // Abre el archivo de entrada
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }

    // Declaración de variables
    Node* node = nullptr;
    OperationNode* op = nullptr;
    NumberNode* number = nullptr;
    VariableNode* variable = nullptr;
    string line, token;
    stringstream ss;

    // Crea una pila para almacenar los nodos de operación
    stack<Node*> stack;

    // Asigna nullptr como valor inicial al puntero source
    this->source = nullptr;

    // Lee la primera línea del archivo
    if (getline(file, line, '\n')) {
        ss.str(line);

        // Procesa cada token en la línea
        while (getline(ss, token, ' ')) {
            // Si el token es una operación
            if (token == "+" || token == "*" || token == "-" || token == "^" || token == "/") {
                // Crea un nuevo nodo de operación y lo agrega a la pila
                node = new OperationNode(token[0]);
                if (!stack.empty()) {
                    op = static_cast<OperationNode*>(stack.top());
                    // Si hay más de dos operaciones consecutivas, agrega las operaciones anteriores al árbol
                    while (op->getLeft() != nullptr && op->getRight() != nullptr) {
                        stack.pop();
                        if (!stack.empty()) {
                            OperationNode* parentOp = static_cast<OperationNode*>(stack.top());
                            if (parentOp->getLeft() == nullptr) {
                                parentOp->setLeft(op);
                            } else {
                                parentOp->setRight(op);
                            }
                            op = parentOp;
                        } else {
                            this->source = op;
                            break;
                        }
                    }
                }
                stack.push(node);
            }
            // Si el token es un número
            else if (token[0] >= '0' && token[0] <= '9') {
                // Crea un nuevo nodo de número y lo agrega como hijo del nodo de operación superior en la pila
                number = new NumberNode(stoi(token));
                if (!stack.empty()) {
                    op = static_cast<OperationNode*>(stack.top());
                    if (op->getLeft() == nullptr){
                        op->setLeft(number);
                    }
                    else {
                        op->setRight(number);
                        stack.pop();
                        // Si hay un nodo de operación padre en la pila, agrega el nodo de operación como hijo del nodo de operación padre
                        if (!stack.empty()) {
                            OperationNode* parentOp = static_cast<OperationNode*>(stack.top());
                            if (parentOp->getLeft() == nullptr) {
                                parentOp->setLeft(op);
                            } else {
                                parentOp->setRight(op);
                            }
                        } else {
                            this->source = op;
                        }
                    }
                }
            } 
            // Si el token es una variable
            else{
                // Crea un nuevo nodo de variable y lo agrega como hijo del nodo de operación superior en la pila
                variable = new VariableNode(token);
                if (!stack.empty()) {
                    op = static_cast<OperationNode*>(stack.top());
                    if (op->getLeft() == nullptr)
                        op->setLeft(variable);
                    else {
                        op->setRight(variable);
                        stack.pop();
                        // Si hay un nodo de operación padre en la pila, agrega el nodo de operación como hijo del nodo de operación padre
                        if (!stack.empty()) {
                            OperationNode* parentOp = static_cast<OperationNode*>(stack.top());
                            if (parentOp->getLeft() == nullptr) {
                                parentOp->setLeft(op);
                            } else {
                                parentOp->setRight(op);
                            }
                        } else {
                            this->source = op;
                        }
                    }
                }
            }
        }

        // Después de procesar la línea de entrada, maneja los nodos restantes en la pila
        while (!stack.empty()) {
            op = static_cast<OperationNode*>(stack.top());
            stack.pop();
            if (!stack.empty()) {
                OperationNode* parentOp = static_cast<OperationNode*>(stack.top());
                if (parentOp->getLeft() == nullptr) {
                    parentOp->setLeft(op);
                } else {
                    parentOp->setRight(op);
                }
            } else {
                this->source = op;
            }
        }
    } 
    else {
        cout << "No se pudo leer la linea" << endl;
        return false;
    }

    file.close();

    return true;
}



/*
double SymbolicProcessor::evaluateExpression(Node* expression) {
    
}

Node* SymbolicProcessor::simplifyExpression(Node* expression) {
    
}

Node* SymbolicProcessor::differentiateExpression(Node* expression) {
    
}
*/
