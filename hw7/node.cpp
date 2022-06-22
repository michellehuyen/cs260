#include "node.h"

Node::Node() {
    val = 0;
    next = NULL;
}

int Node::get_val() const {
    return val;
}

class Node* Node::get_next() const {
    return next;
}

void Node::set_val(int v) {
    val = v;
}

void Node::set_next(Node* n) {
    next = n;
}