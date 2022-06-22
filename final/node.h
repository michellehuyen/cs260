#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Node {
    private:
        int val;
        vector<Node*> neighbors;
        Node *next;
        Node *prev;
        bool visited;
    public:
        Node();
        Node(int);

        int get_val() const;
        Node *get_next() const;
        Node *get_prev() const;
        bool get_visited() const;

        void set_val(int);
        void set_next(Node*);
        void set_prev(Node*);
        void set_visited(bool);

        void addEdge(Node*);
        int printEdge();

        void addNeighbor(Node*);
        Node* get_neighbor(int);
        int get_numNeighbors();
};