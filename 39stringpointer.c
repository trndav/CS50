#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
// #define MAX_LENGTH 50
int main(void)
{
    char *string = "Bundija!";
    for (int i=0; i<8; i++)
    {
        printf("String address is: %p.\n", (string+i));
        printf("String is: %c.\n", string[+i]);
    }
}
