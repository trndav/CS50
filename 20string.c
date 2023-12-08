#include <stdio.h>
#include <string.h> // strlen
int main(void) 
{
    char name[] = "Emma";
    int length = strlen(name);
    for (int i=0; i<length; i++)
    {
    printf("%c ", name[i]);
    printf("%i ", name[i]);
    }
}