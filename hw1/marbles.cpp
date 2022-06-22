#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void checkChoice(int& c) {
    while (c != 1 && c != 2) {
        cout << "Please enter a valid input." << endl;
        cout << "Enter 1 to add a marble to your bag, enter 2 to remove a marble from your bag: ";
        cin >> c;
        if (cin.fail()) {
            cin.clear();
            cin.ignore (9999, '\n');
            cin >> c;
        }
    }
}

int addMarbles(int& nMarbles) {
    nMarbles += 1;

    return nMarbles;
}

int removeMarbles(int& nMarbles) {
    if (nMarbles < 1) {
        cout << "You do not have any marbles in your bag to remove." << endl;
    }
    else {
        nMarbles -= 1;
    }

    return nMarbles;
}

void checkAgain(int& a) {
    while (a != 1 && a != 2) {
        cout << "Please enter a valid input." << endl;
        cout << "Enter 1 to continue, enter 2 to quit: ";
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cin >> a;
        }
    }
}

int main() {
    int choice = 0, numMarbles = 0, again = 0;
    do {
        cout << endl;
        cout << "Enter 1 to add a marble to your marble bag, enter 2 to remove a marble from your bag: ";
        cin >> choice;
        cout << endl;

        checkChoice(choice);

        if (choice == 1) {
            addMarbles(numMarbles);
        }
        else {
            removeMarbles(numMarbles);
        }

        cout << "There are " << numMarbles << " marbles in your bag." << endl << endl;

        cout << "Enter 1 to continue, enter 2 to quit: ";
        cin >> again;

        checkAgain(again);

    } while (again == 1);

    return 0;
}