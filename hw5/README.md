1. Create an array-based list or a linked-list (and a bonus for attempting both) that:
    1. automatically inserts values in the correct position based on some order of sorting (perhaps ascending integers or lexicographical sorting of words)
        - Insert the values at the end of the list then call the sortElem() function to sort out the values.
        - Create a new list and give the new list's head the head of the old list.
        - Traverse the old list while comparing the values of the old list with the ones in the new list
        - If a value from the old list is smaller than the head of the new list then make the value from the old list the head.
        - Else, traverse the new list until you find a value bigger than or equal the value from the old list.
            - If you've reached the end of the new list and still have found a place for that value then insert it at the tail.
            - Else, place the value from the old list before the value that's bigger than it in the new list.
    
    2. efficiently searches for elements (likely binary search for the array list, but what about the linked-list?)
        - Traverse the linked list until you find the element you're looking for.
        - If the element the user requested for doesn't exist in the list then return -1 and let the user know it doesn't exist.
        - If the user tries to search for an element in an empty list then let them know the list is empty.

2. Make a chart to compare the algorithmic complexity (use Big-O notation) of your insert, remove, and search algorithms you used for your structures
    - Insert algorithm: O(1)
    - Sort ascending algorthm: O(n^2)
    - Search algorithm: O(n)