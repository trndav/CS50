#include <stdio.h>
int main() {
    char terms;
    printf("Do you agree? ");
    scanf("%c", &terms);
    if (terms == 'y' || terms == 'Y')
    {
        printf("You accepted terms.\n");
    }
    else if (terms == 'n' || terms == 'N')
    {
        printf("You must agree to terms.\n");
    }
}