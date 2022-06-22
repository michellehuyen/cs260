1. Describe the way that you decide on hashing a value
    - create a hash function
    - return the integer the user had input modulo the # of buckets in the hash table

2. An insert function that places the value at the appropriate location based on its hash value
    - check to see if the hash table is NULL at that location and if it is then place the value at that location
    - if the hash table isn't NULL at that location check the following:
        - if the value at that location is equal to the value that we're trying to insert
            - if they're equal then call the contains function letting the user know this is a repeat value and delete the value
        - check to see if the next value in the list is NULL
            - if not NULL then traverse the list to see if the value at that location is equal to the value we're trying to insert
            - if they're equal call the contains function and delete the value
            - if they're not equal then set that value to become the next one in the list

3. A contains function that returns whether the value is already in the hashtable
    - traverse the table to check if the value we're trying to insert already exists