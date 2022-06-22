#include "node.h"

class BST {
    private:
        Node *root;
    public:
        BST();

        Node* get_root() const;

        void insert(int);
        void insertLR(Node*, int);
        void remove(int);
        Node* findParentOfReplacementVal(Node*);
        Node* findReplacementVal(Node*);
        void removeLR(Node*, int);
        void checkForChildren(Node*, Node*);

        void inOrderTraversal(Node*);
        void preOrderTraversal(Node*);
        void postOrderTraversal(Node*);

        void deleteTree(Node*);

        ~BST();
};