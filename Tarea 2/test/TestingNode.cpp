#include "Node.h"

int main() {
    Node *node = new Node();
    int nodeType = node->getType();
    std::cout << "Node type: " << nodeType << std::endl;

    delete(node);

    return 0;
}
