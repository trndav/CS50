#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi
#include <ctype.h>
#define MAX_LENGTH 600
// ci = (pi + k) % 26

int isNumeric(char *str);
void addToEachCharacter(char *str, int key);

int main(int argc, char *argv[])
{
    // Check if there are 2 arguments (start + key)
    if (argc != 2 || !isNumeric(argv[1]))
    //  || atoi(argv[1]) < 1 || atoi(argv[1]) > 9
    {        
        printf("Usage: ./caesar key\n");  
        return 1;     
    }    

    // Convert arg to number and check if it is bigger than 0 and smaller than 9
    int key;
    key = atoi(argv[1]);    
    printf("Key is: %i\n", key);

    char text[MAX_LENGTH];
    printf("plaintext:  ");
    fgets(text, sizeof(text), stdin);
    printf("%s", text);
    
    addToEachCharacter(text, key);
    printf("ciphertext:  %s", text);
}

// Check if all characters are number
int isNumeric(char *str) 
{
    while (*str) 
    {
        if (!isdigit(*str)) 
        {
            return 0; // Return 0 if any character is not a digit
        }
        str++;
    }
    return 1; // Return 1 if all characters are digits
}

// Adding 3 to the ASCII value of the character
void addToEachCharacter(char *str, int key) 
{
    while (*str != '\0') {
        if (isalpha(*str)) {
            char base = isupper(*str) ? 'A' : 'a';
            *str = ((*str - base + key) % 26) + base;
        }
        str++;
    }
}
