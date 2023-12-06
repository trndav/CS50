#include <stdio.h>
int main(void)
{
    long number1;
    long number2;
    printf("Enter first number: ");
    scanf("%li", &number1);
    printf("Enter second number: ");
    scanf("%li", &number2);
    double z = (double) number1 / (double) number2;
    printf("%.20f\n", z);
}