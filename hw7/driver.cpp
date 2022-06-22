#include "hash.h"

void checkAgain(int &a);

void checkAgain(int &a) {
    while (a != 1 && a != 2) {
        cout << endl;
        cout << "Please enter a valid number !" << endl;
        cout << "Enter 1 to continue" << endl;
        cout << "Enter 2 to quit" << endl;
        cout << "Enter a number (1-2): ";
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cin >> a;
        }
    }
}

int main() {
    int num = 0, count = 0, collisions = 0, again = 0;
    Hash h(26);

    // h.insert(30);
    // h.insert(9);
    // h.insert(30);
    // h.insert(40);
    // h.insert(8);
    // h.insert(6);

    do {
        cout << endl;

        cout << "Enter some number: ";
        cin >> num;

        while (cin.fail()) {
            cout << endl;
            cin.clear();
            cin.ignore(9999,'\n');
            cout << "Please enter a number !" << endl;
            cout << "Enter some number: ";
            cin >> num;
            cout << endl;
        }

        cout << endl;
        h.insert(num);
        // h.contains(num);
        cout << endl;
        h.display();
        
        cout << endl;

        cout << "Enter 1 to continue" << endl;
        cout << "Enter 2 to quit" << endl;
        cout << "Enter a number (1-2): ";
        cin >> again;

        checkAgain(again);

    } while (again != 2);

    cout << endl;

    return 0;
}