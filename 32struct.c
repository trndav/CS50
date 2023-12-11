#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#define MAX_LENGTH 50
typedef struct
{
    char *names;
    char *numbers;
}
person;

int main(void) 
{
    person people[2];
    people[0].names = "Adminbro";
    people[0].numbers = "+385-665-883-534";
    people[1].names = "Bob";
    people[1].numbers = "+042-995-899-599";

    char name[MAX_LENGTH];
    printf("Type name you want to see phone number: \n");
    scanf("%s", name);
    for ( int i=0; i<2; i++)
    {
        if (strcmp(name, people[i].names) == 0)
        {
            printf("Number of %s is: %s. \n", name, people[i].numbers);
            return 0;
        }
    }
    printf("Number is not in phone book.");
    return 1;
}