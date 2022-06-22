#include "queue.h"

void checkChoice (int &c);

void checkChoice (int &c) {
    while (c != 1 && c != 2 && c != 3 && c != 4) {

        cout  << endl;

        cout << "Please enter a valid input." << endl;
        cout << "Enter 1 to add a random number to the queue" << endl;
        cout << "Enter 2 to remove the first element" << endl;
        cout << "Enter 3 to see the first value in the queue" << endl;
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
    Queue q;
    int choice = 0, num;
    srand(time(NULL));

    do {
        cout << endl;
        cout << "Enter 1 to add a random number from 1-10" << endl;
        cout << "Enter 2 to remove the first element" << endl;
        cout << "Enter 3 to see the first element in the queue" << endl;
        cout << "Enter 4 to quit" << endl;
        cout << "Enter a number (1-4): ";
        cin >> choice;

        checkChoice(choice);

        cout << endl;

        if (choice == 1) {
            num = rand()%10 + 1;
            q.enqueue(num);
            // wrote line 48 bc before I had my print_elem() function, I didn't know what values were being passed into the enqueue function
            // wanted to have a way to keep track of the values in the queue to make sure the other functions were being implemented correctly.
            // cout << "Rando num: " << num << endl;
        }
        else if (choice == 2) {
            cout << "This was the head before it was removed: " << q.dequeue() << endl;
            // wrote line 53 bc i wanted to make sure the head would become the next element in line rather than some other #.
            // cout << "This is the new head: " << q.get_head() << endl;
        }
        else if (choice == 3) {
            cout << "Value at the front of the queue: " << q.peek() << endl;
        }
        // decided to make a print_elem() function to make it easier for me to see all the elements and make sure my other functions
        // work the way they should.
        q.print_elem();
        
        cout << endl;
    } while (choice != 4);

    return 0;
}