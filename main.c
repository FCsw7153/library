#include <stdio.h>

struct Node {
    int Value;
    struct Node *next;
};

// insertNode to insert data into link_list
void insertNode(int i, struct Node *p) {
    // new_link_list : new link_list to insert
    // i : data in new_link_list
    // p : link_list
    struct Node *new_link_list;
    new_link_list -> Value = i;
    new_link_list -> next = p -> next;
    p -> next = new_link_list -> next;
}

