#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
// #define MAX_LENGTH 50
int main(void) 
{
    int a = 28;
    int b = 50;
    int *c = &a; // C is pointing to value of a
    *c = 14; // C pointing at value of a, changes variable a value to 14.
    c = &b; // C takes address of b and stores to C.
    *c = 25; // C pointing at value of b, changes variable b value to 25.
    printf("a has value: %i, located at: %p.\n", a, &a);
    printf("b has value: %i, located at: %p.\n", b, &b);
    printf("c has value: %p, located at: %p.\n", c, &c);
    printf("c has value: %i, and %i.\n", c, &c);
}

