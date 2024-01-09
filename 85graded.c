#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h> 
#define MAX_LENGTH 900

int main(void)
{
    char text[MAX_LENGTH];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);
    printf("String is: %s\n", text);

    int letters = 0;
    int words = 0;    
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
           letters++; 
        }  
    }
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' && text[i+1] != ' ')
        {
            words++;    
        }
    }
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;    
        }
    }
    int words1 = words + 1;

    float L = (float)letters / (float)words1 * 100;
    float S = (float)sentences / (float)words1 * 100;
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    int graded = round(grade);
    if (grade < 1)
    {
        printf("Before grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", graded); 
    }    
}
