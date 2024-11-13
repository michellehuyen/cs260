#include <iostream>
#include "node.h"

Node::Node() {
    val = 0;
    next = NULL;
}

int Node::get_val() const {
    return val;
}

int Node::get_left() const {
    return left;
}

int Node::get_right() const {
    return right;
}

class Node* Node::get_next() const {
    return next;
}

void Node::set_val(int v) {
    val = v;
}

void Node::set_left(int l) {
    left = l;
}

void Node::set_right(int r) {
    right = r;
}

void Node::set_next(Node* n) {
    next = n;
}