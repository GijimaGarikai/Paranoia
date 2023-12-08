#pragma once
#include <stdbool.h>
typedef struct {
  int size;
  int capacity;
  char * info;
} charlist;

charlist * make_charlist(void);

int charlist_size (charlist * list);

char charlist_get (charlist * list, int index);

void free_charlist (charlist * list);

void charlist_add(charlist * list, char item);

void print_charlist(charlist *list);

bool charlist_compare(charlist *list1, charlist *list2);

void charlist_copy(charlist *copy, charlist *original);