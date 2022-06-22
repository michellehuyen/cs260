1. add new vertex function
    - create a new node and give it a value
    - loop through the vertices if any to see if the val of the new node already exists in the graph
        - if yes then don't add the new node
        - if no then use push_back to add new node/the vertice to the graph
2. add new edge function
    - loop through the vertices to see if any of the vertices matches the int source and int destination value the user had input
        - if one or none of them match the return NULL
        - else return the node that exists at that index
    - loop through the vertices to find the vertice that matches the int source and int destination value the user had input
    - once the match has been found for the source then at the index it was found at, add a neighbor value of the destination node
    - do the same for the destination node but add a neighbor value of the source node
3. shortest path algorithm
    - loop through the vertices to see if any of the vertices matches the int source and int destination value the user had input
        - if one or none of them match the return NULL
        - else return the node that exists at that index
    - loop through the vertices and set all of the boolean visited value to false and set the previous values to false
    - push the source node into the queue
    - in a while loop, make a for loop where you loop through the number of neighbors that the source node has
    - check to see if that neighbor hasn't been visited, and if it isn't then set the visited value to true and push that neighbor into the queue
    - set the previous value to the front value in the queue
    - print out the path by storing the destination value into the visiting node.
    - in a while loop where the visiting node does not equal NULL, print out the visiting value and then set the visiting value to the previous value
4. minimum spanning tree algorithm
    - use the breadth-first search algorithm
    - make sure that it is a connected graph?
    - loop through the vertices to see if any of the vertices matches the int source the user had input
        - if there is no match then return NULL
        - else return the node that exists at that index
    - start at the int source vertice and keep track of its neighbors
    - once you've reached the last vertice of the connected graph, print out the shortest path from the int source to the last vertice of the connected graph??