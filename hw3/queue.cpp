#include "queue.h"

Queue::Queue() {
    head = NULL;
    tail = NULL;
}

// made this function to test and see if when the head becomes a new value, it becomes the value next in line
// int Queue::get_head() const {
//     return head->get_val();
// }

void Queue::enqueue(int val) {
    // creates and sets the new node.
    class Link *new_link = new Link;
    new_link->set_val(val);
    new_link->set_next(NULL);

    // checks to see if there is anything in the queue.
    // If there's nothing then set both the head and tail to new_link bc it holds the value of the rand #.
    if (head == NULL) {
        head = new_link;
        tail = new_link;
    }
    // if the queue already has elements in it, set the tail by pointing it to
    // the next empty space in line and placing new_link there (bc it holds the rand #).
    else {
        tail->set_next(new_link);
        tail = new_link;
    }
}

int Queue::peek() {
    // if the user is trying to return the first element in the queue while it's empty then return 0.
    if (head == NULL) {
        return 0;
    }
    // if there is an element in the queue then return that first element.
    else {
        return head->get_val();
    }
}

int Queue::dequeue() {
    // if the user is trying to remove the head/first element in the queue while it's empty them return 0.
    if (head == NULL) {
        return 0;
    }
    else {
        // if there are elements in the queue, then create an int variable that will hold the val of current head
        // so that we can store its value and return it after changing the head to become the next element in line.
        int head_val = head->get_val();
        // creating a ptr variable pointing to class Link to point to the element next to the head.
        class Link *head_next = head->get_next();

        // deleting the current head and setting it to head_next which is just the element that was next to the head we just deleted.
        delete head;
        head = head_next;

        // if the head that we just deleted happens to be the only element that was in the queue, then the new head will become NULL,
        // and if head is NULL then we also need tail to be NULL.
        if (head == NULL) {
            tail = NULL;
        }
        // returning the head_val bc that's the purpose of this function is to return the val of the new head value after deleting
        // the old head value.
        return head_val;
    }
}

// this function just traverses the queue and prints out everything that's in there.
void Queue::print_elem() {
    // created a ptr variable w/ the name tmp pointing to class Link and setting that to the head bc
    // we don't want to change the value of the actual head when traversing the queue.
    class Link *tmp = head;
    cout << "Elements in queue: ";
    while (tmp != NULL) {
        cout << tmp->get_val() << " ";
        tmp = tmp->get_next();
    }
    cout << endl;
}

// the destructor just frees everything from the queue
Queue::~Queue() {
    // created a ptr variable w/ the name tmp pointing to class Link and setting that to the head
    class Link *tmp = head;

    while (head != NULL) {
        // tmp is the temporary head so we want to point that temporary head to whatever is next to it and then delete the actual head.
        // After the actual head is deleted, set its value to tmp bc that's the next element in line. Do this until the queue is empty.
        tmp = tmp->get_next();
        delete head;
        head = tmp;
    }
}
