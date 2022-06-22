#include "hash.h"

Hash::Hash(int num) {
    bucket = num;
    numItems = 0;
    hashTable = new Node*[num];

    for (int i = 0; i < num; i++) {
        hashTable[i] = NULL;
    }
}

// int Hash::get_numItems() const {
//     return numItems;
// }

int Hash::hashFunction(int x) {
    return x % bucket;
}

void Hash::insert(int key) {
    // cout << "inside insert function!" << endl;
    int hashIndex = hashFunction(key);

    // cout << "key: " << key << endl;
    // cout << "hashIndex: " << hashIndex << endl;

    class Node *tmp = new Node;
    tmp->set_val(key);
    tmp->set_next(NULL);

    // if that specific index is NULL then place that value at that index
    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = tmp;
    }
    // if that specific index isn't NULL
    else {
        // cout << "Inside else statement of insert func" << endl;

        class Node *traverse = hashTable[hashIndex];
        // int traverseIndex = hashFunction(traverse->get_val());
        // cout << "traverse->get_val(): " << traverse->get_val() << endl << endl;

        // check to see if the value at that index is the same value as the one we're trying to insert
        // if they are equal, call the contains function to let them know the value they're trying to
        // insert already exists and delete the value
        if (traverse->get_val() == key) {
            // cout << "if " << traverse->get_val() << " = " << key << endl;
            // cout << "same val" << endl << endl;
            contains(key);
            delete tmp;
            return;
        }

        // if they are not equal, check to see if the next value is NULL
        // if the next value isn't NULL, then traverse the list to see if any of the values in the list are equal
        // to the one the user is trying to insert
        // if there is a value in the list that matches with the value the user is trying to insert,
        // call the contains function to let them know the value they're trying to insert already exists and delete the value
        // if there isn't a value in the list that matches with the value the user is trying to insert,
        // set that value to become the next one in the list
        else {
            while (traverse->get_next() != NULL) {
                // cout << "if " << traverse->get_val() << " = " << key << endl;

                if (traverse->get_next()->get_val() == key) {
                    // cout << "if " << traverse->get_val() << " = " << key << endl;
                    // cout << "same val" << endl << endl;
                    contains(key);
                    delete tmp;
                    return;
                }
                traverse = traverse->get_next();
            }
            traverse->set_next(tmp);
        }
    }

    // keep track of the number of values we're inerting into the table
    numItems++;
    cout << "Number of items in table: " << numItems << endl;
}

bool Hash::contains(int key) {
    // cout << "inside contains func" << endl;
    
    int hashIndex = hashFunction(key);

    // if there are no values at this specific index, then
    // return false because there can't be any matching values if there are no values to begin with
    if (hashTable[hashIndex] == NULL) {
        return false;
    }

    // if there are value(s) at this specific index, then
    // traverse the list to find the repeated value and return true while letting the user know
    // that the value already exists
    else {
        for (int i = 0; i < bucket; i++) {
            class Node *traverse = hashTable[i];
            while (traverse != NULL) {
                // cout << "traverse->get_val(): " << traverse->get_val() << endl;
                if (traverse->get_val() == key) {
                    cout << "The value " << key << " already exists !" << endl; 
                    return true;
                }
                traverse = traverse->get_next();
            }
        }
    }
    return false;
}

void Hash::display() {
    // traverse the table and lists and print everything out
    for (int i = 0; i < bucket; i++) {
        class Node *traverse = hashTable[i];
        if (traverse != NULL) {
            cout << i;
            if (traverse->get_next() == NULL) {
                cout << " -> "<< traverse->get_val() << endl;
            }
            // cout << " -> "<< traverse->get_val() << endl;
            else {
                while (traverse->get_next() != NULL) {
                    cout << " -> "<< traverse->get_val() << " -> " << traverse->get_next()->get_val() << endl;
                    traverse = traverse->get_next();
                }
                // traverse = traverse->get_next();
            }
            // cout << " -> "<< hashTable[i]->get_val() << endl;
            // cout << hashTable[i]->get_val() << "(" << i << ")" << " ";
        }
    }
}

Hash::~Hash() {
    for (int i = 0; i < bucket; i++) {
        if (hashTable[i] != NULL) {
            delete hashTable[i];
        }
    }
    delete [] hashTable;
}