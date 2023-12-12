#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
// #define MAX_LENGTH 50
int collatz(int number);
int main(void)
{
    int prompt;
    printf("Type a number to calculate Collatz:\n");
    scanf("%i", &prompt);
    collatz(prompt);
    return 0;
}
int collatz(int number)
{
    int counter = 0;
    printf("%i ", number);
    while (number != 1) {
        if (number % 2 == 0) {
            number = number / 2;
        } else {
            number = number * 3 + 1;
        }
        printf("%i ", number); // Print the number in the sequence
        counter++; // Increment the counter
    }
}
