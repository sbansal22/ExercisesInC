/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    // FILL THIS IN!
    int ret = -1;
    Node *next = NULL;

    if (*list == NULL) {
        return ret;
    }

    next = (*list)->next;
    ret = (*list)->val;
    free(*list);
    *list = next;

    return ret;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    // FILL THIS IN!
    Node * new;
    new = (Node *) malloc(sizeof(Node));

    new->val = val;
    new->next = *list;
    *list = new;
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    // FILL THIS IN!
    Node * current = *list;
    Node * prev = current;
    current = prev->next;
    while (current != NULL){
    
        // Case I - when the head node value is equal
        // to the given value
        if (prev->val == val) {
            *list = current;
            // Exactly one node has been rmeoved
            return 1;
        }

        // Case II - when a non-head node value is 
        // equal to the given value
        if (current->val == val){
            prev->next = current->next;
            return 1;
        }

    prev = current;
    current = prev->next;
    }   
}

/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    // FILL THIS IN!
    Node * current = *list;
    Node * prev = current;
    // Creating a node to always be next to the
    // current node
    Node * itercurrent = prev->next;
    prev->next = NULL;
    while(itercurrent != NULL){
        // Iterating to the next node
        current = itercurrent;
        itercurrent = current->next;
        // For a pair, assigning the pointer
        // from the next node to the previous node
        current->next = prev;
        prev = current;
    }
    *list = current;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
