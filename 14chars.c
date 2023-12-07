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
}