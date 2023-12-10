#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
// #define MAX_LENGTH 50

int main() {
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int arraylength = sizeof(numbers);
    int guess;
    printf("Type a number you want to search from array: %i\n", arraylength);
    scanf("%i", &guess);
    for (int i=0; i<7; i++)
    {
        if (numbers[i] == guess)
        {
            printf("You are correct! Number %i is in array!", guess);
            return 0;
        }
    }
    printf("Not correct!");
    return 1;
}