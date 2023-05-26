#include "SymbolicProcessor.h"
#include "OperationNode.h"
#include "NumberNode.h"
#include "VariableNode.h"
#include "math.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stack>

using namespace std;

std::map<char, std::function<int(int, int)>> SymbolicProcessor::operations = {
    {'+', SymbolicProcessor::addition},
    {'-', SymbolicProcessor::subtraction},
    {'*', SymbolicProcessor::multiplication},
    {'/', SymbolicProcessor::division},
    {'^', [](int a, int b) { return std::pow(a, b); }} // Using a lambda function for pow
};

Node* SymbolicProcessor::getSource(){
    return this->source;
}

void SymbolicProcessor::setSource(Node* newSource){
    this->source = newSource;
}

bool SymbolicProcessor::getVariables(){
    return this->variables;
}

bool SymbolicProcessor::load(string filename) {
    // Abre el archivo de entrada
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }
    this->variables = false;
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
                this->variables = true;   // Se avisa que hay variables en el arbol sintactico, para que las operaciones realizables sean Derivar y simplificar
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


NumberNode* SymbolicProcessor::evaluateExpression(Node *expression){
    if(expression->getType() == NUMBER){
        return static_cast<NumberNode*>(expression);
    }
    int result;
    OperationNode *temp = static_cast<OperationNode*>(expression);
    int operand1 = evaluateExpression(temp->getLeft())->getValue();
    int operand2 = evaluateExpression(temp->getRight())->getValue();
    
    result = operations[temp->getOperation()](operand1, operand2);
    
    return new NumberNode(result);
}

Node* SymbolicProcessor::simplifyExpression(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (OperationNode* opNode = dynamic_cast<OperationNode*>(node)) {
        opNode->setLeft(simplifyExpression(opNode->getLeft()));
        opNode->setRight(simplifyExpression(opNode->getRight()));

        // Simplificar expresiones de números
        if (NumberNode* leftNumber = dynamic_cast<NumberNode*>(opNode->getLeft())) {
            if (NumberNode* rightNumber = dynamic_cast<NumberNode*>(opNode->getRight())) {
                std::function<int(int, int)> operation = operations[opNode->getOperation()];
                int result = operation(leftNumber->getValue(), rightNumber->getValue());
                return new NumberNode(result);
            }
        }

        // Simplificar multiplicación por 1
        if (opNode->getOperation() == '*') {
            if (NumberNode* leftNumber = dynamic_cast<NumberNode*>(opNode->getLeft())) {
                if (leftNumber->getValue() == 1) {
                    return opNode->getRight();
                }
            }
            if (NumberNode* rightNumber = dynamic_cast<NumberNode*>(opNode->getRight())) {
                if (rightNumber->getValue() == 1) {
                    return opNode->getLeft();
                }
            }
        }

        // Simplificar suma de un 0
        if (opNode->getOperation() == '+') {
            if (NumberNode* leftNumber = dynamic_cast<NumberNode*>(opNode->getLeft())) {
                if (leftNumber->getValue() == 0) {
                    return opNode->getRight();
                }
            }
            if (NumberNode* rightNumber = dynamic_cast<NumberNode*>(opNode->getRight())) {
                if (rightNumber->getValue() == 0) {
                    return opNode->getLeft();
                }
            }
        }


        // Simplificar resta de una variable consigo misma
        if (opNode->getOperation() == '-' && opNode->getLeft()->getType() == VARIABLE && opNode->getRight()->getType() == VARIABLE) {
            VariableNode* leftVarNode = dynamic_cast<VariableNode*>(opNode->getLeft());
            VariableNode* rightVarNode = dynamic_cast<VariableNode*>(opNode->getRight());
            if (leftVarNode->getVariable() == rightVarNode->getVariable()) {
                return new NumberNode(0);
            }
        }
    }

    return node;
}









/*

Node* SymbolicProcessor::differentiateExpression(){
    
}
*/

//Funciones propias para calculos
    int SymbolicProcessor::addition(int operand1, int operand2){
            return operand1 + operand2;
    }
    int SymbolicProcessor::subtraction(int operand1, int operand2){
        return operand1 - operand2;
    }
    int SymbolicProcessor::multiplication(int operand1, int operand2){
        return operand1 * operand2;
    }
    int SymbolicProcessor::division(int operand1, int operand2){
        return operand1 / operand2;
    }