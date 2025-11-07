#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define KEY_LEN 26

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char key[KEY_LEN + 1];
    char *raw_key = argv[1];

    if ((int)strlen(raw_key) != KEY_LEN)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    bool seen[KEY_LEN] = {false};
    for (int i = 0; i < KEY_LEN; i++)
    {
        if (!isalpha(raw_key[i]))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }

        int index = toupper(raw_key[i]) - 'A';
        if (seen[index])
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        seen[index] = true;
        key[i] = toupper(raw_key[i]);
    }
    key[KEY_LEN] = '\0';

    int max_len = 100;
    char plaintext[max_len];
    char ciphertext[max_len];
    printf("Plaintext: ");
    fgets(plaintext, max_len, stdin);
    int plaintext_len = strlen(plaintext);

    for (int i = 0; i < plaintext_len; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            ciphertext[i] = plaintext[i];
        }
        else if (islower(plaintext[i]))
        {
            int lowercase_offset = 32;
            ciphertext[i] = tolower(key[(int)plaintext[i] - lowercase_offset - 'A']);
        }
        else
        {
            ciphertext[i] = key[(int)plaintext[i] - 'A'];
        }
    }

    printf("Ciphertext: %s", ciphertext);

    return 0;
}
