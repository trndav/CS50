#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
// #define MAX_LENGTH 50
int factorial(int number);
int main(void)
{
    int number;
    printf("Type number: ");
    scanf("%i", &number);
    printf("%i\n", factorial(number));
}
int factorial(int number)
{
    if (number == 1)
    {
        return 1;
    }
    // Recursion: 
    return number * factorial(number-1);
}

Recursion
int fact(int n)
{
    if (n==0)
    {
        return 1;
    }
    else 
    {
        return n * fact(n-1);
    }
}

// Recursion short
// int fact(int n)
// {
//     if (n==0)
//         return 1;
//     else 
//         return n * fact(n-1);
// }

// Iteration
// int fact2(int n)
// {
//     int product = 1;
//     while (n > 0)
//     {
//         product *= n;
//         n--;
//     }
//     return product;
// }