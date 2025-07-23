#include "graphs.hpp"
#include <windows.h>

node::node(int val) : value(val) {}

node::~node()
{
    for (auto n : otherNodes)
    {
        n->removeNode(this);
    }
}

void node::addNode(node *n)
{
    otherNodes.push_back(n);
    n->otherNodes.push_back(this);
}

void node::removeNode(node *n)
{
    auto it = std::find(otherNodes.begin(), otherNodes.end(), n);
    if (it != otherNodes.end())
    {
        otherNodes.erase(it);
        n->removeNode(this);
    }
}

std::vector<graph *> graph::graphs;

graph::graph(const char gname[])
{
    strncpy_s(name, gname, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
    graphs.push_back(this);
}

graph *graph::findGraph(char gname[])
{
    for (auto g : graphs)
    {
        if (strcmp(g->name, gname) == 0)
        {
            return g;
        }
    }
    return nullptr;
}

std::vector<node *> graph::findNode(int value)
{
    std::vector<node *> result;
    for (auto n : nodes)
    {
        if (n->value == value)
        {
            result.push_back(n);
        }
    }
    return result;
}

void graph::addNode(node *n)
{
    nodes.push_back(n);
}

void graph::removeNode(node *n)
{
    auto it = std::find(nodes.begin(), nodes.end(), n);
    if (it != nodes.end())
    {
        nodes.erase(it);
        delete n;
    }
}