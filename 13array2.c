// #include <stdio.h>
// int main(void)
// {
//     // Array
//     int scores[3];  
//     for (int i=0; i<3; i++)
//     {
//         printf("What is score %i: \n", i+1);
//         scanf("%i", &scores[i]);
//     }
//     // Print average of arrays
//     printf("Average is: %f.", (scores[0] + scores[1] + scores[2])/ (float)3 );
// }

#include <stdio.h>
const int N = 3;
float average(int array[]);
int main(void)
{
    int scores[N];  
    for (int i=0; i<N; i++)
    {
        printf("What is score %i: \n", i+1);
        scanf("%i", &scores[i]);
    }
    printf("Average is: %f.", average(scores));
}

float average(int array[])
{
    int sum = 0;
    for (int i=0; i<N; i++)
    {
        sum = sum + array[i];
    }
    return sum / (float) N;
}