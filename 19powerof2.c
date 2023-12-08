#include <stdio.h>
#include <string.h>
int main(void) 
{
    int number;
    do
    {
        printf("Type a number 1 to 10: ");
        scanf("%i", &number);
    } while (number < 1 || number > 10);  
    int array[number];  
    array[0]=1;
    printf("%i\n", array[0]);
    // while (number<33)
    for (int i=1; i<number; i++)
    {
        array[i] = array[i-1]*2;
        printf("%i\n", array[i]);
        // number=number*2;
    }  
}