#include <stdio.h>
#include <string.h>
#include <stdbool.h> // bool function
//#define MAX_LENGTH 50
// Bool, is this valid triangle or not. 2 sides must be greatet than third side.
// int valid_triangle(int a, int b, int c);

bool valid_triangle(int num1, int num2, int num3)
{ 
    if (num1<=0 || num2<=0 || num3<=0)
    {
        printf("Number cant be lower than 0.");
        return false;
    }
    if ((num1+num2) > num3 && (num1+num3) > num2 && (num2+num3) > num1)
    {
    printf("This is valid triangle!");
    return 1;
    }
    else
    {
    printf("This is NOT valid triangle!");
    return 0;
    }
}
int main(void) 
{
    int a, b, c;    
    printf("Enter 3 triangle numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    valid_triangle(a, b, c);
    return 0;
}