#include "SymbolicProcessor.h"

// Mapeo de operación y método de cálculo (para evitar usar if o switch en evaluateExpression)
std::map<char, std::function<int(int, int)>> SymbolicProcessor::operations = {
    {'+', SymbolicProcessor::addition},
    {'-', SymbolicProcessor::subtraction},
    {'*', SymbolicProcessor::multiplication},
    {'^', [](int a, int b){return pow(a, b);}} // Se usa una función anónima para la potencia (haciendo uso de pow)
};


// -------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------- Métodos Auxiliares ----------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------


// --------------------------------------------------- Métodos propios para calculos ---------------------------------------------------

/*
    * Método: addition
    * Descripción: Método que suma 2 enteros
    * Parámetros:
    * - operand1: entero
    * - operand2: entero
    * Retorno:
    * - resultado: entero con la suma de los operandos
*/
int SymbolicProcessor::addition(int operand1, int operand2){
    return operand1 + operand2;
}

/*
    * Método: subtraction
    * Descripción: Método que resta 2 enteros
    * Parámetros:
    * - operand1: entero
    * - operand2: entero
    * Retorno:
    * - resultado: entero con la resta de los operandos
*/
int SymbolicProcessor::subtraction(int operand1, int operand2){
    return operand1 - operand2;
}

/*
    * Método: multiplication
    * Descripción: Método que multiplica 2 enteros
    * Parámetros:
    * - operand1: entero
    * - operand2: entero
    * Retorno:
    * - resultado: entero con el producto de los operandos
*/
int SymbolicProcessor::multiplication(int operand1, int operand2){
    return operand1 * operand2;
}



// ---------------------------------------------------- Métodos propios para derivar ---------------------------------------------------

/*
    * Método: deriveAddition
    * Descripción: Derivada de la suma
    * Parámetros:
    * - node: nodo con con el operando de suma y sus respectivos hijos
    * -variable: string con la variable respecto a la cual derivar
    * Retorno:
    * - node: nodo con la expresión ya derivada
*/
Node* SymbolicProcessor::deriveAddition(OperationNode *node, string variable){
    node->setLeft(deriveExpression(node->getLeft(), variable));
    node->setRight(deriveExpression(node->getRight(), variable));
    return node;
}

/*
    * Método: deriveSubtraction
    * Descripción: Derivada de la resta (realmente podría usar la de la suma para ambos pero para ser coherente lo puse igual)
    * Parámetros:
    * - node: nodo con con el operando de resta y sus respectivos hijos
    * -variable: string con la variable respecto a la cual derivar
    * Retorno:
    * - node: nodo con la expresión ya derivada
*/
Node* SymbolicProcessor::deriveSubtraction(OperationNode *node, std::string variable){
    node->setLeft(deriveExpression(node->getLeft(), variable));
    node->setRight(deriveExpression(node->getRight(), variable));
    return node;
}

/*
    * Método: deriveMultiplication
    * Descripción: Derivada del producto
    * Parámetros:
    * - node: nodo con con el operando de multiplicación y sus respectivos hijos
    * -variable: string con la variable respecto a la cual derivar
    * Retorno:
    * - node: nodo con la expresión ya derivada
*/
Node* SymbolicProcessor::deriveMultiplication(OperationNode *node, std::string variable){
    if((node->getLeft()->getType() == NUMBER) && (node->getRight()->getType() == NUMBER)){
        return new NumberNode(0);
    }
    else if(node->getLeft()->getType() == NUMBER){
        node->setRight(deriveExpression(node->getRight(), variable));
    }
    else if(node->getRight()->getType() == NUMBER){
        node->setLeft(deriveExpression(node->getLeft(), variable));
    }
    else{
        OperationNode *left = new OperationNode('*', deriveExpression(node->getLeft(), variable), node->getRight());   // La derivada del primero por el segundo sin derivar
        OperationNode *right = new OperationNode('*', deriveExpression(node->getLeft(), variable), node->getRight());  // La derivada del segundo por el primero sin derivar
        node = new OperationNode('+', left, right);   // Suma de ambos
    }
    return node;
}

/*
    * Método: derivePow
    * Descripción: Derivada de la potencia (x² por ejemplo)
    * Parámetros:
    * - node: nodo con con el operando de potencia ('^') y sus respectivos hijos
    * -variable: string con la variable respecto a la cual derivar
    * Retorno:
    * - node: nodo con la expresión ya derivada
*/
Node* SymbolicProcessor::derivePow(OperationNode* node, string variable) {
    if(node->getLeft()->getType() == NUMBER && node->getRight()->getType() == NUMBER){
        return new NumberNode(0);
    } 
    else{
        if (node->getLeft()->getType() == VARIABLE) {
            if (static_cast<VariableNode*>(node->getLeft())->getVariable() == variable) {
                OperationNode* left = new OperationNode('*', node->getRight(), node->getLeft());
                OperationNode* right = new OperationNode('-', node->getRight(), new NumberNode(1));
                node = new OperationNode('^', left, right); // Suma de ambos
                return node;
            } 
            else{
                return new NumberNode(0);
            }
        }
        else if(node->getRight()->getType() == VARIABLE){
            if (static_cast<VariableNode*>(node->getRight())->getVariable() == variable) {
                return node; // Derivada de un número elevado a x
            } 
            else {
                return new NumberNode(0);
            }
        }
    }
    return node;
}



// -------------------------------------------------- Método auxiliar para simplificar ------------------------------------------------- 

/*
    * Método:
    * Descripción: Toma un nodo cuyos hijos sean OperationNode o NumberNode y los opera recursivamente
    * Parámetros:
    * - expression: Nodo con la expresión a evaluar
    * Retorno:
    * - result: NumberNode con el resultado de la operación
*/
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



// -------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------- Métodos principales ---------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------

/*
    * Método: getSource()
    * Descripción: Adquiere el puntero a la raíz del arbol sintáctico que esta siendo procesado
    * Parámetros:
    * - void
    * Retorno:
    * - source: puntero a la raíz del arbol sintáctico
*/
Node* SymbolicProcessor::getSource(){
    return this->source;
}

/*
    * Método: setSource()
    * Descripción: Cambia el puntero de la raíz del arbol sintáctico para definir una nueva
    * Parámetros:
    * - source: puntero a la nueva raíz
    * Retorno:
    * - void
*/
void SymbolicProcessor::setSource(Node* newSource){
    this->source = newSource;
}

/*
    * Método: load()
    * Descripción: Método que permite leer un archivo con una expresión en notación polaca y convertirla en un árbol sintáctico
    * Parámetros: 
    * - filename: string con el nombre del archivo
    * Retorno:
    * - bool: un booleano que dice si se logró o no leer el archivo
*/
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
            if (token == "+" || token == "*" || token == "-" || token == "^") {
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
    * Método: deriveExpression()
    * Descripción: Método que deriva un árbol sintáctico
    * Parámetros:
    * - node: nodo de un árbol sintáctico (se llama con la raíz del árbol)
    * - variable: string con la variable con respecto a la cual derivar
    * Retorno:
    * - node: nodo con la nueva expresión ya derivada
*/
Node* SymbolicProcessor::deriveExpression(Node* node, string variable){
    if (node == nullptr) {
        return nullptr;
    }

    // Si no es operador, ni tiene la variable en cuestion entonces se retorna la derivada de una constante (0)
    if(node->getType() == NUMBER || (node->getType() == VARIABLE && dynamic_cast<VariableNode*>(node)->getVariable() != variable)){
        return new NumberNode(0);
    }
    
    // De ser una operación entonces se usa la función auxiliar correspondiente
    if(OperationNode* opNode = dynamic_cast<OperationNode*>(node)){
        switch (opNode->getOperation()){
            case '+':
                return deriveAddition(opNode, variable);
                break;
            case '-':
                return deriveSubtraction(opNode, variable);
                break;
            case '*':
                return deriveMultiplication(opNode, variable);
                break;
            case '^':
                return derivePow(opNode, variable);
                break;
            default:
                break;
        }
    }
    //Si llegamos a este punto tenemos la variable en cuestion sola, por lo que se retorna la derivada de la variable sola (1)
    return new NumberNode(1);
}


// Se debe llegar a la menor cantidad de nodos posibles
/*
    * Método: simplifyExrpression
    * Descripción: Método que simplifica un árbol sintáctico para que tenga el menor número de nodos posible
    * Parámetros:
    * - node: Nodo de un árbol sintáctico (se llama con la raíz del árbol)
    * Retorno:
    * - node: nodo con la expresión ya simplificada
*/
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

        // SImplificar elevado a 1 y 0
        if(opNode->getOperation() == '^'){
            if (NumberNode* rightNumber = dynamic_cast<NumberNode*>(opNode->getRight())) {
                if (rightNumber->getValue() == 1) {
                    return opNode->getLeft();
                }
                if (rightNumber->getValue() == 0) {
                    return new NumberNode(1);
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

        // Conmutatividad

        // Distrubición

        // Factorizacióm
    }
    return node;
}