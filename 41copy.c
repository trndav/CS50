#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#define MAX_LENGTH 50
int main(void)
{
    char word[] = "aba!";
    word[0] = toupper(word[0]);
    printf("Word is: %s", word);
}
