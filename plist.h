

#pragma once
#include <stdbool.h>
#include "charlist.h"

typedef struct pnode{
    charlist *value;
    struct pnode *next;
} pnode;
typedef struct{
    pnode *first;
} plist;

pnode* make_node(charlist *name, pnode *next); // allocates a new node on the heap with the given values.

plist* make_list(); // allocates a new, empty list on the heap.

void free_node(pnode *node); // frees the given node.

void free_list(plist *list); // frees the given list.

void list_insert(plist *list, charlist *name); // inserts the given name (as a string) into the end of the list.

bool list_remove(plist *list, charlist *name); // removes the given name from the list, returning true if the name is found and removed and false otherwise.

int list_size(plist *list); // returns the number of elements in the list.

void print_as_target_ring(plist *list); // prints the current list interpreting it as the target ring, e.g., if the list contains the names [John, Jane, Mary], print_as_target_ring would output:

void print_as_tagged_list(plist *list); // prints the current list interpreting it as the tagged list
