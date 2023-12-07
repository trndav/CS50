#include <stdio.h>
int main(void)
{
    // int x = 0;
    // printf("While loop!\n");
    // while (x < 3)
    // {        
    //     printf("x is %i\n", x);
    //     x++;
    // }
    // printf("For loop!\n");
    // for (int y = 0; y < 3;)
    // {
    // printf("For loop is: %i\n", y);
    // y++;
    // }
    int n;
    do
    {
        printf("Guess number up to 10: ");
        scanf("%i", &n);
    } 
    while (n <= 5);    
    printf("Congratulations!");
}