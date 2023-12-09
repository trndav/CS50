#include <stdio.h>
#include <string.h>
#include <stdbool.h> // bool function
//#define MAX_LENGTH 50

int main(void)
{ 
    int number = 5;
    int guess;
    printf("Guess a number: ");
    scanf("%i", &guess);
    if (guess != number)
    {
        printf("Wrong guess!");
    }
    else 
    {
    printf("You are correct!");
    }
}