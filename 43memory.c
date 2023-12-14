#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#define MAX_LENGTH 50
int main() 
{
    int *x = malloc(3*sizeof(int));
    if (x == NULL) {
        return 1;
    }
    x[0] = 73;
    x[1] = 43;
    x[2] = 63;
    free(x);
    return 0;
}

// gcc -o 43memory 43memory.c  # Compile the C code to generate a Linux-compatible executable
// valgrind ./43memory         # Run Valgrind on the compiled binary
