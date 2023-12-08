#include <stdio.h>
#include <string.h> // strlen
#define MAX_LENGTH 50
int main(void) 
{
    char word[MAX_LENGTH];
    int length;
    printf("Enter a word to check is it alphabetical order: ");
    scanf("%s", word);
    length = strlen(word);
    for (int i=0; i<length-1; i++)
    {
        // printf("%c ", word[i]);
        if (word[i] > word[i+1])
        {
        printf("No! It is not.");
        return 0;
        }
    }
    printf("Yes! It is.");
}