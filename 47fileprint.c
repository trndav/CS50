#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#define MAX_LENGTH 50
int main(void) 
{
    char name[MAX_LENGTH];
    char number[MAX_LENGTH];
    FILE *file = fopen("phonebook.csv", "a");
    printf("Type name: \n");
    scanf("%s", name);
    printf("Type number: \n");
    scanf("%s", number);
    fprintf(file, "%s,%s\n", name, number);
    fclose(file);
}

