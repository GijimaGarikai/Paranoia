# Paranoia Game

The Paranoia Game is a simple command-line game implemented in C. The game simulates a circular target ring where players attempt to eliminate each other by selecting targets. The last remaining player is the winner.

## Project Structure

The project consists of several C files and a header file:

- `paranoia.c`: Contains the main logic for the Paranoia game, including the game loop and user input handling.
- `plist.c` and `plist.h`: Implement a linked list data structure to manage the target ring and tagged players.
- `charlist.c` and `charlist.h`: Define a character list data structure and associated functions for managing strings.

## Compilation

When compiling the program, ensure that you also compile the `charlist.c` and `plist.c` files. For example:

```bash
clang -o paranoia paranoia.c charlist.c plist.c
```

## How to Play

1. Run the compiled program.
2. Enter the names of players one by one, pressing Enter after each name.
3. Press Enter again to start the game.
4. During each turn, enter the name of the player you want to tag.
5. The game continues until only one player remains.

## Files

- `paranoia.c`: Implements the game logic and user interaction.
- `plist.c` and `plist.h`: Provide the circular linked list data structure for managing players.
- `charlist.c` and `charlist.h`: Define a character list data structure for managing strings.

## Functions

### Main Functions

- `play_game`: Initiates the Paranoia game and handles the game loop.
- `my_getline`: Reads a line of input from the user.

### Linked List Functions

- `make_node`: Allocates a new node with the given values.
- `make_list`: Allocates a new, empty circular linked list.
- `free_node`: Frees a given node.
- `free_list`: Frees a given circular linked list.
- `list_insert`: Inserts a given name at the end of the list.
- `list_remove`: Removes a given name from the list.
- `list_size`: Returns the number of elements in the list.
- `print_as_target_ring`: Prints the list as the target ring.
- `print_as_tagged_list`: Prints the list as the tagged list.

### Character List Functions

- `make_charlist`: Allocates a new empty character list.
- `charlist_size`: Returns the size of the character list.
- `charlist_get`: Returns the character at the specified index.
- `free_charlist`: Frees the character list and its content.
- `charlist_add`: Adds a character to the end of the character list.
- `print_charlist`: Prints the content of the character list.
- `charlist_compare`: Compares two character lists for equality.
- `charlist_copy`: Copies the content of one character list to another.

## Compilation and Execution

Compile the program using a command like:

```bash
clang -o paranoia paranoia.c charlist.c plist.c
```

Run the compiled program:

```bash
./paranoia
```

Follow the on-screen instructions to play the game.

Enjoy the Paranoia Game!
