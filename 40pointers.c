#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#define MAX_LENGTH 50
int main(void)
{
    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];
    printf("Type first word: ");
    scanf("%s", word1);
    printf("Type first word: ");
    scanf("%s", word2);
    printf("Word 1: %s, word 2: %s.\n", word1, word2);
    if (strcmp(word1, word2) == 0)
    {
        printf("Words are same.");
    }
    else 
    {
        printf("Words are different.");
    }
}
