#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#include <stdint.h> // uint8_t
#define MAX_LENGTH 50

typedef struct node { 
    char phrase[MAX_LENGTH];
    struct node *next;
}
node;

node *table[26];
int hash(char *phrase);

int main(void) {    
    for (int i = 0; i < 3; i++) // Add items to list
    {
        char phrase[MAX_LENGTH];
        printf("Type string: ");
        scanf("%s", phrase);        
        int index = hash(phrase);       
        printf("%s hashes to %i\n", phrase, index); 
    }      
}
int hash(char *phrase) {
    return toupper(phrase[0]) - 'A';
}