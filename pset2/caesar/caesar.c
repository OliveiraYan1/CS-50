#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check the number of arguments

    if (argc != 2)
    {
        printf("Insert a valid argument.\n");
        return 1;
    }

    // check if the argument has only numbers
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {

        char tmp = argv[1][i];

        if (isdigit(tmp) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // convert the argument to an integer

    int k = atoi(argv[1]);

    // get the plaintext

    string PLAINTEXT = get_string("plaintext: ");

    // printingg

    printf("ciphertext: ");

    // encrypting

    for (int i = 0, n = strlen(PLAINTEXT); i < n; i++)
    {
        char tmp = PLAINTEXT[i];

        if (isalpha(tmp) != 0)
        {
            // UPPERCASE LETTERS
            if (isupper(tmp) != 0)
            {
                tmp = (((tmp - 65) + k) % 26) + 65;
            }
            else // LOWERCASE LETTERS
            {
                tmp = (((tmp - 97) + k) % 26) + 97;
            }
        }
        else // punctuations
        {
            tmp = PLAINTEXT[i];
        }

        printf("%c", tmp);
    }

    printf("\n");
}
