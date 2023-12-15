#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#include <stdint.h> // uint8_t
//#define MAX_LENGTH 50
int main(int argc, char *argv[]) {
    if (argc != 2)
    {
        printf("After run command, app needs more arguments.");
        return 1;
    }
    int filename_length = strlen(argv[1]);
    // Create block of memory to store filename_length
    char *filename = malloc(sizeof(char) * (filename_length +1));
    // Copy argv[1] into block of memmory for filename
    sprintf(filename, "%s", argv[1]);
    // Open new file under name stored at filename
    FILE *new_file = fopen(filename, "w");
    if (new_file == NULL)
    {
        printf("Cant create file.");
        return 1;
    }
    fclose(new_file);
    free(filename);
}