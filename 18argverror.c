#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) // argc=argument count, argv=argument vectors
{
    if (argc != 2)
    {
        printf("Missing command line argument.");
        return 1; // echo $? shows false
    }
    else
    {
        printf("Hola, %s!", argv[1]);
        return 0; // echo $? shows true
    }
}