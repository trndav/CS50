#include <stdio.h>
#include <string.h> // strcmp(string compare)
#include <stdbool.h> // bool function
#include <ctype.h> // toupper
#include <stdlib.h>
#include <stdint.h> // uint8_t
//#define MAX_LENGTH 50

int main() {
    // Declare a 2D array with 3 rows and 4 columns
    int myArray[3][4]; // This creates a 3x4 array
    // Initializing the elements of the 2D array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            myArray[i][j] = i * 4 + j; // Assigning values to each element
        }
    }
    // Accessing elements of the 2D array and printing them
    printf("Contents of the 2D array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%i ", myArray[i][j]); // Printing each element
        }
        printf("\n");
    }
    return 0;
}