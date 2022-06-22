#include "list.h"

List::List() {
    head = NULL;
    tail = NULL;
}

// inserts a value at the end of the list and calls sortElem() to sort out the list in ascending order.
void List::addElem(int val) {
    class Link *new_node = new Link;
    new_node->set_val(val);
    new_node->set_next(NULL);

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    else {
        tail->set_next(new_node);
        tail = new_node;
    }
    sortElem();
}

// I have a bunch of rando comments in this function b/c it wasn't working properly (but now it is !)
// At first it would only sort 4 values, then it would replaces numbers rather than add them into the list and sort them
// other times it would seg fault or print out a bunch of numbers nonstop.
void List::sortElem() {
    class Link *tmp = head;

    // created a new list and set the first value in the list as the head of the old list
    class Link *h = NULL, *t = NULL;
    class Link *new_list = new Link;

    new_list->set_val(head->get_val());
    new_list->set_next(NULL);

    if (h == NULL) {
        h = new_list;
        t = new_list;
    }

    // traverse the list with unsorted values
    while (tmp->get_next() != NULL) {

        // cout << "h: " << h->get_val() << endl;
        // cout << "tmp: " << tmp->get_val() << endl;

        // if the value in the unsorted list is less than or equal to the head of the new list
        // insert that value from the unsorted list at the head of the new list and push everything else to the right.
        if (tmp->get_next()->get_val() <= h->get_val()) {

            // cout << "h in if statement: " << h->get_val() << endl;

            class Link *new_node = new Link;
            new_node->set_val(tmp->get_next()->get_val());
            new_node->set_next(h);
            h = new_node;

            // cout << "h in if statement (@ the end): " << h->get_val() << endl << endl;
            // cout << "new_node: " << new_node->get_val() << endl << endl;
            // cout << "new_node->get_next()->get_val(): " << new_node->get_next()->get_val() << endl << endl;
        }
        // if the value in the unsorted list is greater than or equal to the head of the new list
        // traverse through the new list to see where the value from the unsorted list would fit.
        else if (tmp->get_next()->get_val() >= h->get_val()) {
            // cout << "else if " << tmp->get_next()->get_val() << " >= " << h->get_val() << endl << endl;
            class Link *h_ptr = h;
            while (h_ptr != NULL) {
                // cout << "inside h_ptr while loop !" << endl << endl;

                // check to see if the next value in line is NULL and if it is then insert the value at the end of the new list.
                if (h_ptr->get_next() == NULL) {
                    class Link *new_node = new Link;
                    new_node->set_val(tmp->get_next()->get_val());
                    new_node->set_next(NULL);
                    h_ptr->set_next(new_node);
                    t->set_next(new_node);
                    t = new_node;  
                    break;                        
                }
                // if the next value isn't NULL and it is greater than or equal to the value from the unsorted list
                // insert that value before h_ptr and have the value next to it be h_ptr->get_next()->get_val().
                else if (h_ptr->get_next() != NULL && h_ptr->get_next()->get_val() >= tmp->get_next()->get_val()) {

                    // cout << "if " << h_ptr->get_next()->get_val() << " >= " << tmp->get_next()->get_val() << endl << endl;

                    class Link *new_node = new Link;
                    new_node->set_val(tmp->get_next()->get_val());
                    new_node->set_next(h_ptr->get_next());
                    h_ptr->set_next(new_node);

                    // cout << "new_node: " << new_node->get_val() << endl << endl;
                    // cout << "new_node->get_next()->get_val(): " << new_node->get_next()->get_val() << endl << endl;
                    // cout << "h_ptr->get_next()->get_val(): " << h_ptr->get_next()->get_val() << endl << endl;

                    break;
                }
                h_ptr = h_ptr->get_next();
            }
        }
        tmp = tmp->get_next();
    }

    // had this down here to make sure my list was actually sorting the list and inserting all the values into the new list
    // class Link *tmp3 = h;
    // cout << "These are the elements in the list pt.2: ";
    // while (tmp3 != NULL) {
    //     cout << tmp3->get_val() << " ";
    //     tmp3 = tmp3->get_next();
    // }
    // cout << endl;

    // free the old list and then give head and tail the values in the new list.
    while (head != NULL) {
        tmp = tmp->get_next();
        delete head;
        head = tmp;
    }

    if (head == NULL) {
        head = h;
        tail = t;
    }
}

// this function searches for the value in the list and returns its position in the list
int List::searchElem(int findNum) {
    class Link *tmp = head;
    int counter = 0;

    if (head == NULL) {
        cout << "Your list is empty !" << endl;
    }
    
    // traverses the list until the number is found
    while (tmp != NULL) {
        if (tmp->get_val() == findNum) {
            break;
        }
        else {
            tmp = tmp->get_next();
            counter++;
        }
    }

    // return -1 if the number the user was looking for doesn't exist
    if (tmp == NULL || tmp->get_val() != findNum) {
        cout << "This number doesn't exist in the list !" << endl;
        return -1;
    }
    // return 0 if the number was found and let the user know where in the list the number was located @
    else {
        cout << "Found it ! The number you were looking for (" << findNum << ") was in position " << counter << " !" << endl << endl;
        return 0;
    }
}

// this function prints everything in the list
void List::printElem() {
    class Link *tmp = head;

    cout << "These are the elements in the list: ";
    while (tmp != NULL) {
        cout << tmp->get_val() << " ";
        tmp = tmp->get_next();
    }
    cout << endl;
}

// destructor to free everything in the list
List::~List() {
    class Link *tmp = head;

    while (head != NULL) {
        tmp = tmp->get_next();
        delete head;
        head = tmp;
    }
}
