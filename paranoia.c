

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "plist.h"
#include "charlist.h"
// when compiling this program, ensure to have charlist.c and plist.c compiled as well

/*my_getline
PreConditions:
*buf - charlist to store data
*in - input file

PostConditions:
stores all characters input on stdin in buf charlist
*/
int my_getline(charlist *buf, FILE *in) {
  char ch = fgetc(in);
  if (ch == '\n')
    return 0;
  while (ch != '\n') {
    charlist_add(buf, ch);
    ch = fgetc(in);
  }
  charlist_add(buf, '\0');
  return 1;
}

/*play_game
PreConditions:
*targets - a circular list of players still in the game
*tagged - a circular list of players knocked out

PostConditions:
Plays the game Paranoia on the command line
*/
void play_game(plist *targets, plist *tagged){
    charlist *target = make_charlist();
    while (list_size(targets) > 1){
        printf("There are %d people left!\n", list_size(targets));
        printf("\nEnter a target: ");
        target->size = 0;
        my_getline(target, stdin);
        if (list_remove(targets, target)){
            print_charlist(target);
            printf(" was tagged!\n");
            list_insert(tagged, target);
        } else {
            print_charlist(target);
            printf(" is not in the target ring\n");
        }
        print_as_target_ring(targets);
        print_as_tagged_list(tagged);
    }
    free_charlist(target);
    free_list(targets);
    free_list(tagged);
    return;
}

int main(void) {
    printf("Enter a player's name (press enter to begin game): ");
    charlist *name = make_charlist();
    plist *target_ring = make_list();
    plist *tagged_list = make_list();
    int end = my_getline(name, stdin);
    while (end != 0) {
        list_insert(target_ring, name);
        printf("\nEnter another player's name: ");
        name->size = 0;
        end = my_getline(name, stdin);
    }
    print_as_target_ring(target_ring);
    print_as_tagged_list(tagged_list);
    play_game(target_ring, tagged_list);
    return 0;
}