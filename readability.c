#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    // declare an array to store the text
    int max_len = 100000;
    char text[max_len];

    printf("Text: ");
    fgets(text, max_len, stdin);
    int i = 0;
    int sentences = 0;
    int words = 0;
    int letters = 0;
    while (text[i] != '\n')
    {

        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        { // if we run into !, ?, or ., it's a new sentence
            sentences += 1;
            i += 1;
            continue;
        }
        if (text[i] == 32)
        {
            // if we run into a space
            words += 1;
            i += 1;
            continue;
        }
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        i += 1;
    }
    words++;

    printf("letters: %i\n", letters);
    printf("words: %i\n", words);
    printf("sentences: %i\n", sentences);
    double l = (double)100 * letters / words;
    double s = (double)100 * sentences / words;
    double index = 0.0588 * l - 0.296 * s - 15.8;

    printf("Grade %f\n", index);
    return 0;
}