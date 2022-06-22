#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::cin;

class Link {
    private:
        int val;
        Link *next;
    public:
        Link();

        int get_val() const;
        Link *get_next() const;

        void set_val(int);
        void set_next(class Link*);
};