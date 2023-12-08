#include <stdio.h>
int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';
    char string[] = "Hi!";
    printf("Char: %c%c%c. \n", c1, c2, c3);
    printf("Integer: %i,%i,%i. \n", c1, c2, c3);
    printf("String: %s\n", string);
    printf("String array: %c%c %i%c\n", string[0], string[1], string[3], string[4], string[2]);

    char *stringarray[2]; // Array of pointers to strings
    stringarray[0] = "Hola there!\n";
    stringarray[1] = "Whats up?\n";
    printf("%s%s", stringarray[0], stringarray[1]);
    printf("%c%c%c%c\n", stringarray[0][0], stringarray[0][1], stringarray[0][2], stringarray[0][3]);
    printf("%c%c%c%c\n", stringarray[1][0], stringarray[1][1], stringarray[1][2], stringarray[1][3], stringarray[1][4]);
}