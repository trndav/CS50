#include <stdio.h>
#define MAX_LENGTH 50
int main(void)
{
    char name[MAX_LENGTH];
    int age;
    long long int telephone;
    printf("What is your name? ");
    scanf("%s", name);
    printf("How old are you %s? ", name);
    scanf("%i", &age);
    printf("%s, %i, what is your telephone number? ", name, age);
    scanf("%lli", &telephone);
    printf("Name: %s, age: %i, telephone number: %lli.", name, age, telephone);
}