#include "link.h"

Link::Link() {
    val = 0;
    next = NULL;
}

int Link::get_val() const {
    return val;
}

class Link *Link::get_next() const {
    return next;
}

void Link::set_val(int value) {
    val = value;
}

void Link::set_next(class Link* n) {
    next = n;
}