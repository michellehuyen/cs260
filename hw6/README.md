1. Insert function
    1. check to see if there is a root, and if there isn't then put whatever is the first value is as the root.
    2. if the root isn't NULL, then check to see if the next value to be inserted is less than or greater than the root.
        - If the value is less than or equal to the root then do this:
            1. insert the value to the left of the tree by continuously checking to see if the value is less than or equal to or greater than all the other leaves in the list.
        
        - If the value is greater than the root then do this:
            1. insert the value to the right of the tree by continuously checking to see if the value is less than or equal to or greater than all of the other leaves in the list.

2. Remove function
    1. check to see if there is a root, and if there isn't then let the user know they can't remove anything in an empty tree.
    2. if the root isn't NULL, then check to see if the number the user requested for is less than or equal to the root or greater than the root.
        - If the value requested is less than or equal to the root then do this:
            1. traverse the left side of the root until the number is found.
            2.  if the number isn't found let the user know they requested for a non-existing number in the tree.    
            3. if the number does exist check to see if and how many children it has.           
            4. if the number has a child to the right then we want to get the right value then the farthest left value to replace the number we're about to delete. (inorder successor).          
            5. if the number only has one child then you can just delete the number and replace it with the value to the left or right of the number we are about to delete.
        
        - If the value requested is greater than the root then do this:          
            1. travers the right side of the root and do everything stated above except for the right side of the tree.

3. Traversal function
    1. Inorder travsersal:
        - check to see if root is NULL
        - traverse the left side of the root
        - print out root val
        - travers the right side of the root
    2. Preorder traversal
        - check to see if root is NULL
        - print out root val
        - traverse the left and right side of the root
    3. Postorder traversal
        - check to see if the root is NULL
        - traverse the left and right side of the root
        - print out root val