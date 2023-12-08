

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "plist.h"
#include "charlist.h"


pnode* make_node(charlist *name, pnode *next) {
    pnode *node = malloc(sizeof(pnode));
    node->value = name;
    node->next = next;
    return node;
} // allocates a new node on the heap with the given values.

plist* make_list(void){      
    plist *list = malloc(sizeof(plist));
    list->first = NULL;
    return list;
} // allocates a new, empty list on the heap.

void free_node(pnode *node) {
    if (node == NULL)
        return;
    free(node);

} // frees the given node.

void free_list(plist *list){
    pnode *cur = list->first;
    pnode *next;
    while (cur != NULL) {
        next = cur->next;
        free_charlist(cur->value);
        free_node(cur);
        cur = next;
    }
    free(list);

} // frees the given list.


void list_insert(plist *list, charlist *name) {
    charlist *copy = make_charlist();
    charlist_copy(copy, name);
    pnode *cur = list->first;
    if (cur==NULL){
        list->first = make_node(copy, NULL);
        return;
    }
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = make_node(copy, NULL);

} // inserts the given name (as a string) into the end of the list.

bool list_remove(plist *list, charlist *name){
    pnode *cur = list->first;
    pnode *temp;
    // if it's the first name
    if (charlist_compare(name, cur->value)){
        temp = cur->next;
        list->first = temp;
        free_node(cur);
        return true;
    }
    if (cur->next == NULL){
        return false;
    }
    // while the name doesn't match the next name keep going
    while (!(charlist_compare(name, cur->next->value))) {
        cur = cur->next;
        // we went through all names so it's not in here
        if (cur->next==NULL)             
            return false;
    }
    temp = cur->next;
    cur->next = temp->next;
    free_node(temp);
    return true;

} // removes the given name from the list, returning true if the name is found and removed and false otherwise.

int list_size(plist *list){
    pnode *cur = list->first;
    if (cur == NULL)
        return 0;
    int total = 1;
    while (cur->next != NULL){
        total++;
        cur = cur->next;
    }
    return total;
} // returns the number of elements in the list.


void print_as_target_ring(plist *list){
    pnode *cur = list->first;
    pnode *first = list->first;
    if (cur == NULL){
        printf("There are no targets left!\n");
        return;
    }
    if (cur->next == NULL){
        print_charlist(cur->value);
        printf(" is the final person remaining!\n");
        return;
    }
    while (cur->next!=NULL){
        print_charlist(cur->value);
        printf(" is stalking ");
        print_charlist(cur->next->value);
        printf("\n");
        cur = cur->next;
    }
    print_charlist(cur->value);
    printf(" is stalking ");
    print_charlist(first->value);
    printf("\n");
    
} // prints the current list interpreting it as the target ring, e.g., if the list contains the names [John, Jane, Mary], print_as_target_ring would output:


void print_as_tagged_list(plist *list){
    pnode *cur = list->first;
    pnode *first = list->first;
    if (cur==NULL){
        printf("No people have been tagged yet!\n");
        return;
    }
    printf("Tagged list:\n");
    print_charlist(first->value);
    printf("\n");
    cur = cur->next;
    while (cur!=NULL){
        print_charlist(cur->value);
        cur = cur->next;
        printf("\n");
    }
} // prints the current list interpreting it as the tagged list