#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#include <stdint.h> // uint8_t
//#define MAX_LENGTH 50

int fact(int n)
{
    if ( n == 1 )
        return 1;
    else
        printf("%i\n", n);
        return n * fact(n-1);
}

int main(void)
{
    printf("%i", fact(5));
}