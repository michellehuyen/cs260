#include "list.h"

void checkChoice(int &c);

void checkChoice(int &c) {
    while (c != 1 && c != 2 && c != 3 && c != 4) {
        cout << endl;
        cout << "Please enter a valid input." << endl;
        cout << "Enter 1 to add a random # (1-10) to the list" << endl;
        cout << "Enter 2 to remove a random # from the list" << endl;
        cout << "Enter 3 to return a # at a specific position" << endl;
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

int main() {
    List l;
    srand(time(NULL));
    int choice = 0, insert = 0, option = 0, remove = 0, position = 0, randNum;

    do {
        cout << endl;

        cout << "Enter 1 to add a random # (1-10) to the list" << endl;
        cout << "Enter 2 to remove a # from the list" << endl;
        cout << "Enter 3 to return a # at a specific position" << endl;
        cout << "Enter 4 to quit" << endl;
        cout << "Enter a number (1-4): ";
        cin >> choice;

        checkChoice(choice);
        
        cout << endl;

        if (choice == 1) {
            randNum = rand()%10 + 1;
            // cout << "This is the random number: " << randNum << endl;
            cout << "Enter a number for the position: ";
            cin >> insert;
            l.add_elem(randNum, insert);
        }
        else if (choice == 2) {
            cout << "Enter the position of the number you would like to remove: ";
            cin >> remove;
            cout << "This was the value that has been removed: " << l.remove_elem(remove) << endl << endl;
            // if (l.remove_elem(remove) == -1) {
            //     cout << "This position does not exist !" << endl;
            //     cout << "Enter a new position #: ";
            //     cin >> remove;
            //     while (l.remove_elem(remove) == -1) {
            //         cout << "This position does not exist !" << endl;
            //         cout << "Enter a new position # in the length " << l.remove_elem(remove) << ": ";
            //         cin >> remove;
            //         if (cin.fail()) {
            //             cin.clear();
            //             cin.ignore(9999, '\n');
            //             cin >> remove;
            //         }
            //     }
            // }
        }
        else if (choice == 3) {
            cout << "Enter the position of the number you would like to return: ";
            cin >> position;
            cout << endl;

            // the bottom was something i added so that if the user enter a position # that's out of bounds
            // i would make them input another #, but i didn't feel like actually adding it in even though i think it works.
            // (@ least it worked when i tried running it).
            // if (l.valAtPos(position) == -1) {
            //     cout << "This position does not exist !" << endl;
            //     cout << "Enter a new position #: ";
            //     cin >> position;
            //     while (l.valAtPos(position) == -1) {
            //         cout << "This position does not exist !" << endl;
            //         cout << "Enter a new position # in the length " << l.count_elem() << ": ";
            //         cin >> position;
            //         if (cin.fail()) {
            //             cin.clear();
            //             cin.ignore(9999, '\n');
            //             cin >> position;
            //         }
            //     }
            // }
            cout << "The value at position " << position << " is: " << l.valAtPos(position) << endl;
        }
        l.print_elem();
    } while (choice != 4);

    cout << endl;
    return 0;
}