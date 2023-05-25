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
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return false;
    }

    OperationNode* op = nullptr;
    NumberNode* number = nullptr;
    VariableNode* variable = nullptr;
    string line, token;
    stringstream ss;

    stack<OperationNode*> stack;

    // Asignar nullptr como valor inicial al puntero source
    this->source = nullptr;

    if (getline(file, line, '\n')) {
        ss.str(line);

        while (getline(ss, token, ' ')) {
            if (token == "+" || token == "*" || token == "-" || token == "^") {
                op = new OperationNode(token[0]);
                stack.push(op);
            } else if (token[0] >= '0' && token[0] <= '9') {
                number = new NumberNode(stoi(token));
                op = stack.top();
                if (op->getLeft() == nullptr)
                    op->setLeft(number);
                else {
                    op->setRight(number);
                    stack.pop();
                    delete op;
                }
            } else {
                variable = new VariableNode(token);
                op = stack.top();
                if (op->getLeft() == nullptr)
                    op->setLeft(variable);
                else {
                    op->setRight(variable);
                    stack.pop();
                    delete op;
                }
            }
        }
    } else {
        cout << "No se pudo leer la linea" << endl;
        return false;
    }

    if (!stack.empty()) {
        this->source = stack.top();
        stack.pop();
    }

    file.close();

    cout << "\n\n";

    if (this->source != nullptr) {
        this->source->printTree();
    }

    cout << "\n\n";

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
