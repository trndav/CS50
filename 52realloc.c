#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#include <stdint.h> // uint8_t
//#define MAX_LENGTH 50

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL) {
        return 1;
    }
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;
    int *tmp = realloc(list, 4 * sizeof(int)); // Increase size of list fro 3 to 4
    if ( tmp == NULL) {
        free(list);
        return 1;
    }
    list[3] = 4;
    list = tmp;
    for (int i = 0; i < 4; i++) {
        printf("%i\n", list[i]);
    }
    free(list);
    return 0;
}