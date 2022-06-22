#include "link.h"

class List {
    private:
        Link* head;
        Link* tail;
    public:
        List();

        void add_elem(int, int);
        int remove_elem(int);
        int valAtPos(int);

        int count_elem();
        void print_elem();

        ~List();
};