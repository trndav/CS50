#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH]; // Changed to an array to store the name
    int votes;
} candidate;

candidate get_candidate(const char *prompt); // Changed the argument to a const char pointer

int main(void) {
    // candidate president;
    // president = get_candidate("");
    // printf("Candidate name: %s\n", president.name);
    // printf("Votes: %i\n", president.votes);
    // return 0;
    candidate candidates_array[3];
    for (int i=0; i<3; i++)
    {
        printf("Enter candidate name: ");
        scanf("%s", candidates_array[i].name);
        printf("Enter votes: ");
        scanf("%i", &candidates_array[i].votes);
    }
    for (int i = 0; i < 3; i++) 
    {
        printf("Candidate name: %s\n", candidates_array[i].name);
        printf("Votes: %i\n", candidates_array[i].votes);
    }
}
candidate get_candidate(const char *prompt) {
    printf("%s", prompt);
    candidate c;
    printf("Enter a name: ");
    scanf("%s", c.name);

    printf("Enter votes: ");
    scanf("%i", &c.votes); // Use & to get the address of the votes variable

    return c;
}
