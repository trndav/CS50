#include <stdio.h>
int main(void)
{
    // TODO: Prompt for start size
    long lamas, goal, year = 0;       
    do
    {   
        printf("How many lamas you have? "); 
        scanf("%li", &lamas);
    } while ( lamas < 9);    
    printf("You have %li lamas.\n", lamas);
    // TODO: Prompt for end size
    do
    {
        printf("How much lamas you need to have? ");
        scanf("%li", &goal);
    } while ( goal < lamas );
    printf("Goal is %li lamas.\n", goal);    
    // TODO: Calculate number of years until we reach threshold
    do
    {
        long birth = (lamas * 1/3);
        long dead = (lamas * 1/4);
        // TODO: Print number of years
        printf("Year %li, %li lamas born, %li lamas dead. You now have %li lamas. ", year, birth, dead, lamas);
        year++;
        lamas = lamas + birth - dead;
    } while ( lamas < goal ); 
}

// #include <cs50.h>
// #include <stdio.h>

// int main(void)
// {
//     // TODO: Prompt for start size
//     long lamas;
//     long goal;
//     long year = 0;
//     do
//     {
//         lamas = get_int("Start size: ");
//     }
//     while (lamas < 9);
//         // printf("You have %li lamas.\n", lamas);

//     // TODO: Prompt for end size
//     do
//     {
//         goal = get_int("End size: ");
//     }
//     while ( goal < lamas );
//         // printf("Goal is %li lamas.\n", goal);
//     do
//     {
//         long birth = (lamas * 1/3);
//         long dead = (lamas * 1/4);
//         year++;
//         lamas = lamas + birth - dead;
//     }
//     while ( lamas < goal );

//     printf("Years: %li \n", year);
// }
