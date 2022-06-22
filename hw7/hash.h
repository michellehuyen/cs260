#include "node.h"

class Hash {
    private:
        int bucket;
        int numItems;
        Node **hashTable;
    public:
        Hash(int);

        // int get_numItems() const;

        int hashFunction(int);

        void insert(int);
        bool contains(int);

        void display();

        ~Hash();
};