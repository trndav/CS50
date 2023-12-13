#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
// #define MAX_LENGTH 50
int main(void)
{
    int n = 50;
    int b = 40;
    int *pointer = &n;  // & Provides the address of something stored in memory.
                        // * Instructs the compiler to go to a location in memory.
    int *pointer2 = &b;
    char string[] = "Hola!";
    printf("Number is: %i.\n", n); // %p with &n will print address of variable
    printf("Pointer of n is: %p.\n", pointer); // call pointer address
    printf("When %%p, n, this is result: %p.\n", n);
    printf("*****\n", n);
    printf("Number is: %i.\n", b);
    printf("Pointer 2 as int is: %i.\n", pointer2);
    printf("*****\n", n);
    printf("String is: %s.\n", string);

}
