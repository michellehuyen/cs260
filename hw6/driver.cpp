#include "bst.h"

void checkChoice(int &c);
void printOptionCheck(int &p);

void checkChoice(int &c) {
    while (c != 1 && c != 2 && c != 3 && c != 4) {
        cout << endl;
        cout << "Please enter a valid input !" << endl; 
        cout << "Enter 1 to add a rando number" << endl;
        cout << "Enter 2 to remove" << endl;
        cout << "Enter 3 to print tree" << endl;
        cout << "Enter 4 to quit" << endl;
        cout << "Enter a number (1-4): ";
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cin >> c;
        }
    }
}

void printOptionCheck(int &p) {
    while (p != 1 && p != 2 && p != 3) {
        cout << endl;
        cout << "Please enter a valid input !" << endl; 
        cout << "Enter 1 to print the inorder traversal of the tree" << endl;
        cout << "Enter 2 to print the preorder traversal of the tree" << endl;
        cout << "Enter 3 to print the postorder traversal of the tree" << endl;
        cout << "Enter a number (1-3): ";
        cin >> p;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cin >> p;
        }
    }
}

int main() {
    BST tree;
    int choice = 0, randNum = 0, removeNum = 0, printOption = 0;
    srand(time(NULL));

    do {
        cout << endl;
        cout << "Enter 1 to add a rando number" << endl;
        cout << "Enter 2 to remove" << endl;
        cout << "Enter 3 to print tree" << endl;
        cout << "Enter 4 to quit" << endl;
        cout << "Enter a number (1-4): ";
        cin >> choice;

        checkChoice(choice);

        if (choice == 1) {
            randNum = rand() % 20 + 1;
            // cout << "randNum: " << randNum << endl;
            tree.insert(randNum);
            // tree.insert(8);
            // tree.insert(3);
            // tree.insert(1);
            // tree.insert(6);
            // tree.insert(4);
            // tree.insert(7);
            // tree.insert(10);
            // tree.insert(14);
            // tree.insert(13);
        }
        else if (choice == 2) {
            cout << "Enter the number you would like to remove from the tree: ";
            cin >> removeNum;
            tree.remove(removeNum);
            // tree.remove(8);
            // tree.remove(10);
            // tree.remove(3);
            // tree.remove(4);
        }

        else if (choice == 3) {
            cout << endl;

            cout << "Enter 1 to print the inorder traversal of the tree" << endl;
            cout << "Enter 2 to print the preorder traversal of the tree" << endl;
            cout << "Enter 3 to print the postorder traversal of the tree" << endl;
            cout << "Enter a number (1-3): ";
            cin >> printOption;

            printOptionCheck(printOption);

            class Node *root = tree.get_root();
            if (printOption == 1) {
                cout << endl;
                tree.inOrderTraversal(root);
                cout << endl;
            }
            else if (printOption == 2) {
                cout << endl;
                tree.preOrderTraversal(root);
                cout << endl;
            }
            else if (printOption == 3) {
                cout << endl;
                tree.postOrderTraversal(root);
                cout << endl;
            }
        }
    } while (choice != 4);

    cout << endl;
    
    return 0;
}