#include <stdio.h>
#define MAX_LENGTH 50
int main() {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    printf("Enter your first name: ");
    scanf("%s", firstName);
    printf("Enter your last name: ");
    scanf("%s", lastName);
    printf("Hello %s %s\n", firstName, lastName);
    return 0;
}
