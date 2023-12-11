#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
// #define MAX_LENGTH 50
void draw(int n);
int main(void) 
{
    int height;
    printf("Type number of bricks height: \n");
    scanf("%i", &height);
    draw(height);
}
void draw(int n)
{
    if (n<=0)
    {
        return 0;
    }
    draw(n-1);
    for (int i=0; i<n; i++)
    {
        printf("#");
    }
    printf("\n");
}