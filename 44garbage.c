#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#define MAX_LENGTH 50
int main(void) 
{
    int scores[1024];
    for (int i=0; i<10; i++) 
    {
        printf("Number: %i.\n", scores[i]);
    }
}

// This script produces garbage, bc scores array is not initialized
// free(scores);
// return 0;
// gcc -o 43memory 43memory.c  # Compile the C code to generate a Linux-compatible executable
// valgrind ./43memory         # Run Valgrind on the compiled binary
