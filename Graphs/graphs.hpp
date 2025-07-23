#include <vector>
#include <algorithm>
#include <cstring>

struct node
{
    int value;
    std::vector<node *> otherNodes;

    node(int val);

    ~node();

    void addNode(node *n);

    void removeNode(node *n);
};

class graph
{
public:
    std::vector<node *> nodes;

    char name[100];

    static std::vector<graph *> graphs;

    graph(const char gname[]);

    static graph *
    findGraph(char gname[]);

    std::vector<node *> findNode(int value);

    void addNode(node *n);

    void removeNode(node *n);
};