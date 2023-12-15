#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#include <stdint.h> // uint8_t
//#define MAX_LENGTH 50
int main(int argc, char *argv[]) {
    uint8_t pdfcheck[] = {37, 80, 68, 70};
    if (argc != 2)
    {
        printf("Improper usage. 1 argument + start command is required.\n");
        return 1;
    }
    // Open file
    char *filename = argv[1]; // That will be name of file, after run command
    FILE *file = fopen(filename, "r"); // Created file pointer named file
    if (file == NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }
    uint8_t buffer[4]; // unsigned integer uint, 8 bits-1 byte, _t means type. Needs stdint library.
    fread(buffer, 1, 4, file); // 4 arguments, destination, block size, blocks to read and source
    for (int i = 0; i<4; i++)
    {
        printf("%i \n", buffer[i]);
        if (buffer[i] != pdfcheck[i])
        {
            printf("File is not PDF.");
            fclose(file);
            return 0;
        }
    }
    printf("File is PDF.");
    fclose(file);
    return 0;
}