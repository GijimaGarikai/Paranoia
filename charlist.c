 

#include "charlist.h"
#include <stdlib.h>
#include <stdio.h>
/* make_charlist
PreConditions:
None:

PostConditions:
returns an empty charlist of size 10
*/

charlist * make_charlist (void) {
  charlist * list = malloc (1 * sizeof(charlist));
  list->info = malloc(10 * sizeof(char));
  list->size = 0;
  list->capacity = 10;
  return list;
}

/* charlist_size
PreConditions:
*list - charlist

PostConditions:
returns the size of charlist
*/
int charlist_size (charlist * list) {
  int stored = list->size;
  return stored;
}

/* charlist_get
PreConditions:
*list - charlist
index - valid integer index

PostConditions:
returns character in charlist stored at index
*/
char charlist_get (charlist * list, int index) {
  char element = list->info[index];
  return element;
}

/* free_charlist
PreConditions:
*list - charlist

PostConditions:
frees content of the charlist and the list itself
*/
void free_charlist (charlist * list) {
  free (list->info);
  free (list);
}

/* charlist_add
PreConditions:
*list - charlist
item - character to be added

PostConditions:
adds item to the end of charlist
*/
void charlist_add(charlist * list, char item) {
  int index, maxcap;
  index = list->size;
  maxcap = list->capacity;
  //check if backing array is full
  if (index >= maxcap) {
    //if full make a new array twice that size and copy old array to new one
    int newcap = 2 * maxcap;
    char * newarr = malloc(newcap * sizeof(char));
    for (int i = 0; i < index; i++) {
      newarr[i] = list->info[i];
    }
    //deallocate space for old array and update variables of charlist
    free (list->info);
    list->info = newarr;
    list->capacity = newcap;
  }
  //add new item to end of array with or without size adjustment
  list->info[index] = item;
  index++;
  list->size = index;
    
}
/* charlist_add
PreConditions:
*list - charlist
item - character to be added

PostConditions:
adds item to the end of charlist
*/
void print_charlist(charlist *list) {
  int idx = 0;
  char cur = list->info[idx];
  while (cur!='\0'){
    printf("%c", cur);
    idx++;
    cur = list->info[idx];
  }
}
/* charlist_compare
PreConditions:
*list1 - charlist to be compared
*list2 - charlist to be compared

PostConditions:
returns true 
*/
bool charlist_compare(charlist *list1, charlist *list2){
  char cur1, cur2;
  int idx = 0;
  cur1 = list1->info[idx];
  cur2 = list2->info[idx];
  while (cur1 == cur2) {
    idx++;
    cur1 = list1->info[idx];
    cur2 = list2->info[idx];
    if (cur1 == cur2 && cur1 == '\0')
      return true;
  }
  return false;
}

void charlist_copy(charlist *copy, charlist *original){
  int idx = 0;
  char cur = original->info[idx];
  while (cur != '\0'){
    charlist_add(copy, cur);
    idx++;
    cur = original->info[idx];
  }
  charlist_add(copy, '\0');
}