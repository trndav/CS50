#include <stdio.h>
#include <string.h> // strlen
#include <ctype.h> // toupper/lower
// #define MAX_LENGHT 50
// int main(void)
// {
//     char before[MAX_LENGHT];
//     printf("Before: ");
//     scanf("%s", before);
//     printf("After: ");
//     for (int i=0; i<strlen(before); i++)
//     {
//         if (before[i] >= 'a' && before[i] <= 'z')
//         {
//             printf("%c", before[i]-32);
//         }
//         else
//         {
//             printf("%c", before[i]);
//         }
//     }
// }

// #define MAX_LENGHT 50
// int main(void)
// {
//     char before[MAX_LENGHT];
//     printf("Before: ");
//     scanf("%s", before);
//     printf("After: ");
//     for (int i=0; i<strlen(before); i++)
//     {
//         if (islower(before[i]))
//         {
//             printf("%c", toupper(before[i]));
//         }
//         else
//         {
//             printf("%c", before[i]);
//         }
//     }
// }

#define MAX_LENGHT 50
int main(void)
{
    char before[MAX_LENGHT];
    printf("Before: ");
    scanf("%s", before);
    printf("After: ");
    for (int i=0, n=strlen(before); i<n; i++)
    {
        printf("%c", toupper(before[i]));
    }
    printf("\n");
}