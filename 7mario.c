#include <stdio.h>
int main(void)
{
    // Get size of bricks
    int bricks;   
    do
    {
        printf("How big is brick?\n");
        scanf("%i", &bricks);
    }
    while (bricks < 1);
    // Print grid of blocks
    for (int i=0; i<bricks; i++)    
    {                
        for (int j=0; j<bricks; j++)
        {
            printf("#");
        }        
        printf("\n");        
    }
}