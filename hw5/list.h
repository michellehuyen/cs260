#include "link.h"

class List {
    private:
        Link* head;
        Link* tail;
    public:
        List();

        void addElem(int);
        void sortElem();
        int searchElem(int);

        void printElem();

        ~List();
};
