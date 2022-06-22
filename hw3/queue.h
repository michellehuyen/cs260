#include "link.h"

class Queue {
    private:
        Link *head;
        Link *tail;
    public:
        Queue();

        // int get_head() const;

        void enqueue(int);
        int peek();
        int dequeue();

        void print_elem();

        ~Queue();
};