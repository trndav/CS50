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
    int *c = &a;
    c = &b;
    printf("Memory address of 'a' is: %p\n", &a);
    printf("i of c is: %i.\n", *c);
    printf("p-c is %p. p-&b address is: %p. \n", c, &b);
    printf("p-c is %p, %i. \n", c, *c);
}


