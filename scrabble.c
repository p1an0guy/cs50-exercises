#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // declare score system
    int scores[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // declare character strings of max_len to store input
    int max_len = 15; // scrabble only allows words of up to 15 letters
    char p1[max_len], p2[max_len];

    // prompt player 1 for input, store
    printf("Player 1: ");
    scanf("%15s", p1);
    printf("\n");

    // prompt player 2 for input, store
    printf("Player 2: ");
    scanf("%15s", p2);
    printf("\n");

    // convert them into scores
    int score1 = 0;
    for (int i = 0; i < strlen(p1); i++)
    {
        if (isalpha(p1[i]))
        {
            score1 += scores[toupper(p1[i]) - 65];
        }
    }

    int score2 = 0;
    for (int i = 0; i < strlen(p2); i++)
    {
        if (isalpha(p2[i]))
        {
            score2 += scores[toupper(p2[i]) - 65];
        }
    }
    // compare the scores
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
        return 0;
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
        return 0;
    }
    else
    {
        printf("Tie!\n");
        return 0;
    }
}