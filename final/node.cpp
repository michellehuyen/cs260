#include "node.h"

Node::Node() {
    val = 0;
    next = NULL;
    prev = NULL;
    visited = false;
}

int Node::get_val() const {
    return val;
}

Node* Node::get_next() const {
    return next;
}

Node * Node::get_prev() const {
    return prev;
}

bool Node::get_visited() const {
    return visited;
}

void Node::set_val(int v) {
    val = v;
}

void Node::set_next(Node* n) {
    next = n;
}

void Node::set_prev(Node* p) {
    prev = p;
}

void Node::set_visited(bool v) {
    visited = v;
}

void Node::addNeighbor(Node* n) {
    neighbors.push_back(n);
}

Node* Node::get_neighbor(int idx) {
    return neighbors.at(idx);
}

int Node::get_numNeighbors() {
    return neighbors.size();
}