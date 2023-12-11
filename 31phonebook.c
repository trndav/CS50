#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#define MAX_LENGTH 50
int main(void) 
{
    char name[MAX_LENGTH];
    char *names[] = {"Adminbro", "Bob"};
    char *numbers[] = {"+385-665-883-534", "+042-995-899-599"};
    printf("Type name you want to see phone number: \n");
    scanf("%s", name);
    for ( int i=0; i<2; i++)
    {
        if (strcmp(name, names[i]) == 0)
        {
            printf("Number of %s is: %s. \n", name, numbers[i]);
            return 0;
        }
    }
    printf("Number is not in phone book.");
    return 1;
}