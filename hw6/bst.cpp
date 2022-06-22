#include "bst.h"

BST::BST() {
    root = NULL;
}

Node* BST::get_root() const {
    return root;
}

void BST::insert(int val) {
    class Node *new_node = new Node;
    new_node->set_val(val);

    new_node->set_left(NULL);
    new_node->set_right(NULL);

    if (root == NULL) {
        root = new_node;
    }
    else {
        insertLR(root, val);
    }
    // called this function just to make sure that my insert function was working properly
    // cout << endl;
    // inOrderTraversal(root);
    // cout << endl;
}

void BST::insertLR(Node *leaf, int num) {
    class Node *new_node = new Node;
    new_node->set_val(num);

    new_node->set_left(NULL);
    new_node->set_right(NULL);

    if (num <= leaf->get_val()) {
        if (leaf->get_left() == NULL) {
            leaf->set_left(new_node);
        }
        else {
            insertLR(leaf->get_left(), num);
        }
    }
    else if (num > leaf->get_val()) {
        if (leaf->get_right() == NULL) {
            leaf->set_right(new_node);
        }
        else {
            insertLR(leaf->get_right(), num);
        }
    }
}

void BST::remove(int val) {
    if (root == NULL) {
        cout << "There's nothing in this tree for you to remove !" << endl;
    }
    else if (root->get_val() == val) {
        if (root->get_left() == NULL && root->get_right() == NULL) {
            cout << "The tree is now empty !" << endl;
            delete root;
            root = NULL;
        }
        else if (root->get_left() != NULL && root->get_right() != NULL) {
            if (root->get_right()->get_left() != NULL) {
                class Node *new_root = findParentOfReplacementVal(root->get_right());
                
                delete root;
                root = NULL;
                root = new_root->get_left();

                delete new_root->get_left();
                new_root->set_left(NULL);
            }
            else {
                class Node *new_root = root->get_right();
                new_root->set_left(root->get_left());
                root->set_right(root->get_right()->get_right());

                delete root;
                root = new_root;
            }
        }
        else if (root->get_left() != NULL && root->get_right() == NULL) {
            class Node *new_root = root->get_left();
            root->set_left(NULL);

            delete root;

            root = NULL;
            root = new_root;
        }
        else if (root->get_left() == NULL && root->get_right() != NULL) {
            class Node *new_root = root->get_right();
            root->set_right(NULL);

            delete root;
            root = NULL;

            root = new_root;
        }
    }
    else {
        removeLR(root, val);
    }
    // called this function just to make sure that my remove function was working properly
    // cout << endl;
    // inOrderTraversal(root);
    // cout << endl;
}

// this function finds the value that comes before the one we are trying to delete
Node* BST::findParentOfReplacementVal(Node* leaf) {
    while (leaf->get_left()->get_left() != NULL) {
        findParentOfReplacementVal(leaf->get_left());
    }
    return leaf;
}

// this function finds the value that is going to replace the one we are trying to delete
Node* BST::findReplacementVal(Node *leaf) {
    while (leaf->get_left()->get_left() != NULL) {
        findReplacementVal(leaf->get_left());
    }
    return leaf;
}

void BST::removeLR(Node* parent, int num) {
    if (num <= parent->get_left()->get_val()) {
        if (parent->get_left()->get_val() == num) {
            // passing the number before the one that == num into the checkForChildren function
            // also passing the number that we are trying to remove into the checkForChildren function
            // cout << "got here" << endl;
            checkForChildren(parent, parent->get_left());
        }
        else {
            removeLR(parent->get_left(), num);
        }
    }
    else if (num >= parent->get_right()->get_val()) {
        if (parent->get_right()->get_val() == num) {
            // passing the number before the one that == num into the checkForChildren function
            // also passing the number that we are trying to remove into the checkForChildren function
            checkForChildren(parent, parent->get_right());
        }
        else {
            removeLR(parent->get_right(), num);
        }
    }
    else {
        cout << "This number doesn't exist!" << endl;
    }
}

// checking to see how many children the node we are trying to remove has, and using inorder successor to replace the node.
// there are some rando comments in here b/c there was something wrong with it and i didn't know where the problem was coming from
void BST::checkForChildren(Node* parent, Node* leaf) {
    if (leaf->get_left() == NULL && leaf->get_right() == NULL) {
        if (parent->get_left() == leaf) {
            parent->set_left(NULL);
        }
        else {
            parent->set_right(NULL);
        }
        delete leaf;
    }
    // removing a node with 2 children
    else if (leaf->get_left() != NULL && leaf->get_right() != NULL) {
        class Node* leaf_val = leaf;
        if (leaf->get_right()->get_left() != NULL) {
            // cout << "leaf->get_right()->get_left(): " << leaf->get_right()->get_left()->get_val() << endl;
            // class Node *replacement_val = findReplacementVal(leaf->get_right()->get_left());
            class Node *replacement_val = findReplacementVal(leaf->get_right());

            // cout << "replacement_val->get_val(): " << replacement_val->get_val() << endl;
            if (parent->get_left() == leaf) {
                // cout << "yay" << endl;
                parent->set_left(replacement_val->get_left());
            }
            else {
                parent->set_right(replacement_val->get_left());
            }

            replacement_val->get_left()->set_left(leaf_val->get_left());
            replacement_val->get_left()->set_right(leaf_val->get_right());
            
            delete leaf;
            leaf = parent->get_left();
            replacement_val->set_left(NULL);
            // cout << endl;
            // cout << "leaf->get_val(): " << leaf->get_val() << endl;
            // cout << "leaf->get_left()->get_val(): " << leaf->get_left()->get_val() << endl;
            // cout << "leaf->get_right()->get_val(): " << leaf->get_right()->get_val() << endl;
            // if (leaf->get_right()->get_left() == NULL) {
            //     cout << "got it to free that replacement thingy !" << endl;
            // }
            // else {
            //     cout << "leaf->get_right()->get_left()->get_val(): " << leaf->get_right()->get_left()->get_val() << endl;
            // }
        }
        else {
            if (parent->get_left() == leaf) {
                parent->set_left(leaf_val->get_right());
                leaf_val = parent->get_left();
            }
            else if (parent->get_right() == leaf) {
                parent->set_right(leaf_val->get_right());
                leaf_val = parent->get_right();
            }
            leaf_val->set_left(leaf->get_left());

            delete leaf;
            leaf = leaf_val;
        }
    }
    // removing nodes with 1 child
    else if (leaf->get_left() != NULL && leaf->get_right() == NULL) {
        class Node *replacement_val = leaf->get_left();
        parent->set_left(replacement_val);

        delete leaf;
        leaf = parent->get_left();
    }
    else if (leaf->get_left() == NULL && leaf->get_right() != NULL) {
        class Node *replacement_val = leaf->get_right();
        parent->set_right(replacement_val);

        delete leaf;
        leaf = parent->get_right();
    }
}

void BST::inOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->get_left());
    cout << root->get_val() << " ";
    inOrderTraversal(root->get_right());
}

void BST::preOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    cout << root->get_val() << " ";
    preOrderTraversal(root->get_left());
    preOrderTraversal(root->get_right());
}

void BST::postOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->get_left());
    postOrderTraversal(root->get_right());
    cout << root->get_val() << " ";
}

void BST::deleteTree(Node* leaf) {
    if (leaf == NULL) {
        return;
    }

    deleteTree(leaf->get_left());
    deleteTree(leaf->get_right());

    delete leaf;
}

BST::~BST() {
    deleteTree(root);
}