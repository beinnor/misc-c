/* Generic linked list (using void pointer) 
*
*/
#include <stdio.h>
#include <stdlib.h>


/* Node */
struct Node
{
    void *data; // any data type can be stored here
    struct Node *next;
};

/
