#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#define MAX_LENGTH 50
void swap(int *a, int *b);
int main(void) 
{
    int x = 1;
    int y = 2;
    printf("%i and %i.\n", x, y);
    swap(&x, &y);
    printf("%i and %i.", x, y);
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// free(scores);
// return 0;
// gcc -o 43memory 43memory.c  # Compile the C code to generate a Linux-compatible executable
// valgrind ./43memory         # Run Valgrind on the compiled binary
