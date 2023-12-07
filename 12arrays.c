#include <stdio.h>
int main(void)
{
    // Array
    int scores[3];
    printf("Score 1 is: ");
    scanf("%i", &scores[0]);
    printf("Score 2 is: ");
    scanf("%i", &scores[1]);
    printf("Score 3 is: ");
    scanf("%i", &scores[2]);
    // Print average of arrays
    printf("Average is: %f.", (scores[0] + scores[1] + scores[2])/ (float)3 );
}