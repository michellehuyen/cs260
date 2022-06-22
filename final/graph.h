#include "node.h"

class Graph {
    private:
        int val;
        vector<Node*> nodes;
    public:
        Graph();

        void addVertex(int);
        void addEdge(int, int);
        void shortestPath(int, int);
        // void minSpanTree();

        Node* getVertex(int);

        void printGraph();

        ~Graph();
};