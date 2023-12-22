#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#include <stdint.h> // uint8_t
#define MAX_LENGTH 50
// Need to add node in first line bc it is requested in node *next, before node;
typedef struct node { 
    char phrase[MAX_LENGTH];
    struct node *next;
}
node;
#define LIST_SIZE 2
void unload(node *list);
void visualize(node *list);
int main(void) {
    node *list = NULL;
    for (int i = 0; i < LIST_SIZE; i++) // Add items to list
    {
        char phrase[MAX_LENGTH];
        printf("Type string: ");
        scanf("%s", phrase);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Couldn't allocate memory for node\n");
            return 1;
        }
        strncpy(n->phrase, phrase, MAX_LENGTH - 1);
        n->next = list;
        list = n;
        visualize(list);
    }
    unload(list); // Free memory
}
void unload(node *list) { // Free all nodes memory
    while ( list != NULL) {
        node *ptr = list->next;
        free(list);
        list = ptr;
    }
}
void visualize(node *list) {
    printf("\n+-- List Visualizer --+\n\n");
    while (list != NULL) {
        printf("Location: %p\n", list);
        printf("Phrase: %s\n", list->phrase);
        printf("Next: %p\n\n", list->next);
        list = list->next;
    }
    printf("+--------------------+\n");
}
