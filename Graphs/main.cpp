#include <iostream>
#include "graphs.hpp"

int main()
{
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(1);

    n1->addNode(n2);
    n1->addNode(n3);
    n2->addNode(n4);

    n1->removeNode(n2);

    graph g1("Graph1");
    g1.addNode(n1);
    g1.addNode(n2);
    g1.addNode(n3);
    g1.addNode(n4);

    std::vector<node *> foundNodes = g1.findNode(1);
    for (auto n : foundNodes)
    {
        std::cout << "Found node with value: " << n->value << " address: " << n << std::endl;
    }

    std::cout << "\n\npress any key to close this window:";
    std::cin.get();
    return 0;
}