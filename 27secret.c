#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#define MAX_LENGTH 50
bool check_phrase(char[]);
int main(void)
{ 
    char phrase[MAX_LENGTH];
    printf("What is secret phrase? ");
    scanf("%s", phrase);
    bool correct = check_phrase(phrase);
    if (correct == true)
    {
        printf("Come on in! \n");
    }
    else 
    {
        printf("Wrong phrase!");
    }
    return 0;
}
bool check_phrase(char phrase[])
{
    char password[] = "Please";
    if (strcmp(phrase, password) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}