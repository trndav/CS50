#include <stdio.h>
#include <string.h>
// #define MAX_LENGHT 50
int main(int argc, char *argv[]) // argc=argument count, argv=argument vectors
{
    // char name[MAX_LENGHT];
    // printf("What is your name? ");
    // scanf("%s", name);
    // printf("Hi %s!", name);
    printf("Hi, %s %s\n", argv[1], argv[2]); // Start program + ARGUMENT, and get Hi ARGUMENT ./17argc Davor = Hi, Davor
    if (argc == 2)
    {
        printf("Hi %s! ", argv[1]);
    }
    else
    {
        printf("Hello world!");
    }
}