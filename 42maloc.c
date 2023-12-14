#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#define MAX_LENGTH 50
int main(void) {
    char word[] = "aba!";
    char *t = malloc(strlen(word) + 1); // Allocating memory for t
    if (t != NULL) {
        strcpy(t, word); // Copying contents of word to t
        if (strlen(t) > 0) {
            t[0] = toupper(t[0]);
        }
        printf("Word is: %s and %s.\n", word, t);
        printf("Hexadecimal address of word is: %p, and hexadecimal value of first character is: %p\n", word, *word);
        free(t); // Free dynamically allocated memory
    } else {
        printf("Memory allocation failed.\n");
    }
}