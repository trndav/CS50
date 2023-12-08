#include <stdio.h>
#include <string.h>
//#define MAX_LENGTH 50
// Start program with some additional commands like ./22argv Bim Bom Bam
int main(int argc, char *argv[]) // argc=argument count, argv=argument vectors
{
    for (int i = 0; i<argc; i++)
    {
        printf("argv[%i] is: %s\n", i, argv[i]);
    }
}