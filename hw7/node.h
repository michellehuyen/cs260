#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;

class Node {
    private:
        int val;
        Node *next;
    public:
        Node();
        
        int get_val() const;
        Node *get_next() const;

        void set_val(int);
        void set_next(Node*);
};