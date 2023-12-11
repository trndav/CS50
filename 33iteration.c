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
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<i+1; j++)
        {
            printf("#");
        }
        printf("\n");
    }    
}