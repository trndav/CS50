#include <stdio.h>
#include <string.h>
#define MAX_LENGHT 50
int main(void)
{
    char name[MAX_LENGHT];
    printf("What is your name? ");
    scanf("%s", name);
    printf("You typed: %s\n", name);
    int n = 0;
    while (name[n] != '\0') // Counting for characters in string \0 is last character in byte, NUL
    {
        n++;
    }
    printf("Word have: %i characters.\n", n);
    int b = strlen(name);
    printf("With strlen, name is: %i.", b);
}