#include <stdio.h>
#include <string.h>
//#define MAX_LENGTH 50
// 
float multiply(float x, float y);
float multiply(float x, float y)
{
    // float product = x * y;
    // return product;
    return x*y;
}
int main(void) 
{
    float num1, num2;    
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    // Call multiply function and display the result
    float result = multiply(num1, num2);
    printf("The product of %.2f and %.2f is %.2f\n", num1, num2, result);
    return 0;
}