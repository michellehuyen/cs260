1. add_elem(int val, int pos)
    - generate a random number and ask the user where they would like to place the val
    - check to see if the position exists
        - if the user inputs 0 then place the val at the head
        - if the user tries to place the number in a position > 0 in an empty list
          let them know that the list is empty so the number will be placed at the head.
        - if the list isn't empty but the user tries to place it anywhere farther than tail->get_next()
          don't add anything b/c it wouldn't make sense to not have an element at position 3,4,5 but have one at position 10.
        - if the user places the number in a position where there is already a value existing there then create a new node,
          give it a value, set the thing next to the new node to tmp->get_next(), and make sure that tmp->next() is pointing
          to the new node

2. remove_elem(int pos)
    - make sure the position exists and if it doesn't then don't remove anything.
    - traverse through the list until the position and the counter matches, store the value at that position and replace
      it with whatever is next to that value. return the store value.

3. valAtPos(int pos)
    - traverse through the list until the counter matches the position and return whatever value is at that position.