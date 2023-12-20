#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#include <stdint.h> // uint8_t
//#define MAX_LENGTH 50

// On linked lists we cant use element[1,2,3]
// No binary search
typedef struct node { // Need to add node in first line bc it is requested in node *next, before node;
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[]) {
    node *list = NULL;
    for (int i = 1; i < argc; i++) {
        int number = atoi(argv[i]); // atoi, convert string to integer
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return 1;
        }
        n->number = number;
        n->next = NULL;
        n->next = list;
        list = n;
    }
    node *ptr = list;
    while (ptr != NULL) {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }
    ptr = list;
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}
