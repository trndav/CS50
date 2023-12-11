#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#define MAX_LENGTH 50
int main() 
{
    // int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    char *mono[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    char guess[MAX_LENGTH];
    printf("Type a monopoly play-piece you want to search from array: ");
    scanf("%s", &guess);
    for (int i=0; i<6; i++)
    {
        if (strcmp(mono[i], guess) == 0)
        {
            printf("You are correct, %s is in monopoly!", guess);
            return 0;
        }
    }
    printf("Not correct!");
    return 1;
}