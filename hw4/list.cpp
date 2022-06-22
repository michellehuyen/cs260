#include "list.h"

List::List() {
    head = NULL;
    tail = NULL;
}

void List::add_elem(int val, int pos) {
    cout << endl;
    class Link *new_link = new Link;
    new_link->set_val(val);
    new_link->set_next(NULL);

    if (head == NULL) {
        // if the user inputs a position # > 0 for an empty list let them know where it will actually be placed
        if (pos != 0) {
            cout << "There is currently nothing in the list, so we placed the randomly generated number " << val << " in position 0." << endl;
            head = new_link;
            tail = new_link;
        }
        else {
            head = new_link;
            tail = new_link;           
        }
    }
    else {
        class Link *tmp = head;
        class Link *new_node = new Link;

        // if in a non-empty list the user inputs 0 as their position, create a new node, give it a val
        // set head to that new node, then have the new head/new node set the next thing in line to the original head
        if (pos == 0) {
            class Link *new_node = new Link;
            new_node->set_val(val);
            head = new_node;
            new_node->set_next(tmp);
        }

        // the else statement was from an assignment i did for my 162 class at OSU. We had an assignment almost
        // exactly like this one and I was just going to use my code from that assignment for this one, but I decided
        // i wanted everything on my assignment to look the same in how i was traversing through the list using a while loop and counter
        // i also just wanted to try doing this assignment in a different way
        // else {
        //     for (int i = 0; i < pos - 1; i++) {
        //         tmp = tmp->get_next();
        //     }
        //     class Link *new_node = new Link;
        //     new_node->set_val(val);
        //     new_node->set_next(tmp->get_next());
        //     tmp->set_next(new_node);
        // }

        int counter = 1;
        while (tmp != NULL) {
            if (counter == pos) {
                // adds the val to the tail of the list
                if (tmp->get_next() == NULL) {
                    class Link *new_node = new Link;
                    new_node->set_val(val);
                    new_node->set_next(NULL);
                    tmp->set_next(new_node);
                    tail->set_next(new_node);
                    tail = new_node;
                }
                // adds the val to any place of the list other than the head and tail
                else {
                    class Link *new_node = new Link;
                    new_node->set_val(val);

                    new_node->set_next(tmp->get_next());
                    tmp->set_next(new_node);
                }
            }
            tmp = tmp->get_next();
            counter++;
        }
    }
}

int List::remove_elem(int pos) {
    cout << endl;
    if (head == NULL) {
        cout << "Nothing was removed because the list is empty." << endl;
        return 0;
    }
    else {
        class Link *tmp = head;
        int counter = 1;
        
        // if position is 0, store the val of current head and the value next to the head.
        // delete the current head and give the head a new value of whatever was originally next to it.
        if (pos == 0) {
            int head_val = head->get_val();
            class Link *head_next = head->get_next();

            delete head;
            head = head_next;

            if (head == NULL) {
                tail = NULL;
            }
            return head_val;
        }
        // traverse the list until counter matches the position input. once there is a match, create an
        // int variable that stores the value at the requested position. create a node pointer that points to the
        // value next to the one we just stored and delete that tmp value then set it = to the node pointer we created.
        // return the value that we stored in the int variable.
        int elemAtPos;
        while (tmp->get_next() != NULL) {
            if (counter == pos) {
                // i had the line down here before i had the break line b/c for some rzn this function would remove more
                // values than it should so i wanted to see what was happening so i added the line below before realizing i need
                // to break out of the loop.
                // cout << "Counter: " << counter << "Pos: " << pos << endl;
                elemAtPos = tmp->get_next()->get_val();
                class Link *next_elem = tmp->get_next()->get_next();
                
                delete tmp->get_next();
                tmp->set_next(next_elem);
                break;
            }
            else {
                tmp = tmp->get_next();
                counter++;
            }
        }
        if (counter != pos) {
            cout << "This position doesn't exist !" << endl;
            return -1;
        }
        else {
            return elemAtPos;
        }
    }
}

int List::valAtPos(int pos) {
    class Link *tmp = head;
    int counter = 0;
    // traverse the list until the counter is the same as the position input.
    // if the counter matches the position, return whatever value is at that position.
    while (tmp != NULL) {
        if (counter == pos) {
            return tmp->get_val();
        }
        tmp = tmp->get_next();
        counter++;
    }
    // if I get to return -1 that means the position doesn't exist
    return -1;
}

// this function traverses the list and keeps track of the length of the list.
int List::count_elem() {
    int counter = 0;
    class Link *tmp = head;
    while (tmp->get_next() != NULL) {
        tmp = tmp->get_next();
        counter++;
    }

    return counter;

    cout << endl;
}

// this function traverses the list and prints out all the elements.
void List::print_elem() {
    class Link *tmp = head;
    cout << "Elements in list: ";
    while (tmp != NULL) {
        cout << tmp->get_val() << " ";
        tmp = tmp->get_next();
    }
    cout << endl;
}

// this function traverses the list and deletes everything inside the list.
List::~List() {
    class Link *tmp = head;
    while (head != NULL) {
        tmp = tmp->get_next();
        delete head;
        head = tmp;
    }
}