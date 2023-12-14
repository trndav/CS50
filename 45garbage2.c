#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#define MAX_LENGTH 50
int main(void) 
{
    int *x;
    int *y;
    x = malloc(sizeof(int));
    *x = 42; // Go to that address and put value 42
    // *y = 13; // Garbage, points to memory 13?
    y = x;
    *y = 13;
}

// free(scores);
// return 0;
// gcc -o 43memory 43memory.c  # Compile the C code to generate a Linux-compatible executable
// valgrind ./43memory         # Run Valgrind on the compiled binary
