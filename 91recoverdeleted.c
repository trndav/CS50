#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2 )
    {
        printf("Proper usage: ./recover FILE\n");
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file or there is no file.\n");
        return 1;
    }
    uint8_t buffer[512];
    int fileCount = 0;
    FILE *image = NULL;
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] == 0xE0 || buffer[3] == 0xE1))
        {
            if (image != NULL)
            {
                fclose(image);
            }

            char jpegs[8];
            sprintf(jpegs, "%03i.jpg", fileCount);
            fileCount++;

            image = fopen(jpegs, "w");
            if (image == NULL)
            {
                fprintf(stderr, "Could not create %s\n", jpegs);
                fclose(card);
                return 1;
            }
        }
        // Create JPEGs from the data
        if (image != NULL)
        {
            fwrite(buffer, 1, 512, image);
        }
    }
    if (image != NULL)
    {
        fclose(image);
    }
    fclose(card);
    return 0;
}
