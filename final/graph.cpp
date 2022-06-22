#include "graph.h"
#include <queue>
#include <list>

using std::queue;
using std::list;

Graph::Graph() {
    val = 0;
}

void Graph::addVertex(int num) {
    class Node *new_node = new Node;
    new_node->set_val(num);
    new_node->set_next(NULL);

    for (int i = 0; i < nodes.size(); i++) {
        class Node *traverse = nodes.at(i);
        if (traverse->get_val() == num) {
            cout << "The vertex " << num << " already exists in the graph !" << endl;

            delete new_node;
            new_node = NULL;

            return;
        }
    }
    nodes.push_back(new_node);
}

void Graph::addEdge(int src, int dest) {
    Node *src_node = getVertex(src), *dest_node = getVertex(dest);
    if (src_node == NULL || dest_node == NULL) {
        return;
    }

    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i)->get_val() == src) {
            nodes.at(i)->addNeighbor(dest_node);
        }
        else if (nodes.at(i)->get_val() == dest) {
            nodes.at(i)->addNeighbor(src_node);
        }
    }
}

void Graph::shortestPath(int src, int dest) {
    Node *src_node = getVertex(src), *dest_node = getVertex(dest);
    if (src_node == NULL || dest_node == NULL) {
        return;
    }
    for (int i = 0; i < nodes.size(); i++) {
        nodes.at(i)->set_visited(false);
        nodes.at(i)->set_prev(NULL);
    }
    queue<Node*> q;
    Node *visiting;

    q.push(src_node);
    src_node->set_visited(true);
    while (!q.empty()) {
        visiting = q.front();
        q.pop();
        for (int i = 0; i < visiting->get_numNeighbors(); i++) {
            if (visiting->get_neighbor(i)->get_visited() == false) {
                visiting->get_neighbor(i)->set_visited(true);
                q.push(visiting->get_neighbor(i));
                visiting->get_neighbor(i)->set_prev(visiting);
            }
        }
    }

    visiting = dest_node;

    cout << "Path: ";
    while (visiting != NULL) {
        cout << visiting->get_val() << " ";
        visiting = visiting->get_prev();
    }
}

// void Graph::minSpanTree() {
//     Node *src_node = getVertex(nodes.at(0)->get_val());
//     for (int i = 0; i < nodes.size(); i++) {
//         nodes.at(i)->set_visited(false);
//         nodes.at(i)->set_prev(NULL);
//     }
//     queue<Node*> q;
//     Node *visiting;

//     q.push(src_node);
//     src_node->set_visited(true);
//     while (!q.empty()) {
//         visiting = q.front();
//         q.pop();
//         for (int i = 0; i < visiting->get_numNeighbors(); i++) {
//             if (visiting->get_neighbor(i)->get_visited() == false) {
//                 visiting->get_neighbor(i)->set_visited(true);
//                 q.push(visiting->get_neighbor(i));
//                 visiting->get_neighbor(i)->set_prev(visiting);
//             }
//         }
//     }
// }

Node* Graph::getVertex(int val) {
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i)->get_val() == val) {
            return nodes.at(i);
        }
    }
    return NULL;
}

void Graph::printGraph() {
    for (int i = 0; i < nodes.size(); i++) {
        cout << endl;
        cout << "Adjacency list for vertex " << nodes.at(i)->get_val() << ": ";
        for (int j = 0; j < nodes.at(i)->get_numNeighbors(); j++) {
            cout << nodes.at(i)->get_neighbor(j)->get_val() << " ";
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < nodes.size(); i++) {
        delete nodes.at(i);
    }
}