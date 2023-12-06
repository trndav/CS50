#include <stdio.h>
int main(void) 
{
    int number1;
    int number2;
    printf("What is value of x?\n");
    scanf("%i", &number1);
    printf("What is value of y?\n");
    scanf("%i", &number2);
    printf("Numbers you entered are: %i and %i\n", number1, number2);
    if (number1 > number2)
    {
        printf("Number %i is bigger than %i.\n", number1, number2);
    }
    else if (number1 < number2)
    {
        printf("Number %i is less than %i.\n", number1, number2);
    }
    else
    {
        printf("Number %i and %i are even.\n", number1, number2);
    }
}
