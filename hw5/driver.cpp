#include "list.h"

void checkChoice(int &c);

void checkChoice(int &c) {
    while (c != 1 && c != 2 && c != 3) {
        cout << endl;
        cout << "Please enter a valid # !" << endl;
        cout << "Enter 1 to add an element to the list." << endl;
        cout << "Enter 2 to search for an element in the list." << endl;
        cout << "Enter 3 to quit." << endl;
        cout << "Enter a number (1-3): ";
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cin >> c;
        }
    }
}

int main() {
    List l;
    int choice = 0, randNum = 0, findNum = 0;
    srand(time(NULL));

    do {
        cout << endl;
        cout << "Enter 1 to add an element to the list." << endl;
        cout << "Enter 2 to search for an element in the list." << endl;
        cout << "Enter 3 to quit." << endl;
        cout << "Enter a number (1-3): ";
        cin >> choice;

        cout << endl;

        checkChoice(choice);

        if (choice == 1) {
            randNum = rand() % 20 + 1;
            // cout << "randNum: " << randNum << endl;
            l.addElem(randNum);
        }
        if (choice == 2) {
            cout << "Enter the number you're looking for: ";
            cin >> findNum;
            l.searchElem(findNum);
            // if (l.searchElem(findNum) == -1) {
            //     cout << endl;
            //     cout << "This number doesn't exist in the list !" << endl;
            //     cout << "Please enter a different number to look for: ";
            //     cin >> findNum;
            //     while (l.searchElem(findNum) == -1) {
            //         cout << endl;
            //         cout << "This number doesn't exist in the list !" << endl;
            //         cout << "Please enter a different number to look for: ";
            //         cin >> findNum;
            //         if (cin.fail()) {
            //             cin.clear();
            //             cin.ignore(9999, '\n');
            //             cin >> finNum;
            //         }
            //     }
            // }
        }
        l.printElem();
    } while (choice != 3);

    cout << endl;
    return 0;
}