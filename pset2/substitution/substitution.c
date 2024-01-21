#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[])
{

    // CHECK THE NUMBER OF ARGUMENTS

    if (argc != 2)
    {
        printf ("Usage: ./substitution key\n");
        return 1;
    }

    // CHECK THE KEY'S LENGHT

    if (strlen(argv[1]) != 26)
    {
        printf ("key must have 26 characters.\n");
        return 1;
    }

     // CHECKING CHARACTERS THAT IS NOT ALPHABETICAL

     for (int i = 0, n = strlen(argv[1]); i < n; i++)
     {
         if (isalpha (argv[1][i]) == 0)
         {
            printf ("./substitution key\n");
            return 1;
         }
     }

    // LOOKING FOR DUPLICATED CHARACTERS

    // Convert all the characters to lowercase letters

    char lower_temp[26] = {};

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        lower_temp[i] = tolower(argv[1][i]);
    }

    //  Sorting the array

     for (int i = 0, n = strlen(argv[1]); i < n; i++)
     {
         for(int j=i+1; j < strlen(argv[1]); j++)
         {
             if(lower_temp[i] > lower_temp[j])
             {
                 int temp = lower_temp[i];
                 lower_temp[i] = lower_temp[j];
                 lower_temp[j] = temp;
             }
         }
     }

    //  Compare the characters 'i and i+1' to get to know if is the same

     for(int i=0, n = strlen(argv[1]); i < n; i++)
     {
         if (lower_temp[i] == lower_temp[i+1])
         {
             printf ("Key must not contain repeated characters\n");
             return 1;
         }
     }

    // GETTING INPUT FROM THER USER

    string plaintext = get_string("plaintext: ");

    // ENCIPHER

    int n = strlen(plaintext);
    char *ciphertext = malloc(n + 1);

    for (int i = 0; i < n; i++)
    {
         if (isalpha(plaintext[i]) != 0)
         {
             if (isupper(plaintext[i]) != 0)
             {
                 int temp = plaintext[i] - 65;
                 ciphertext[i] = toupper(argv[1][temp]);
             }
             else
             {
                 int temp2 = plaintext[i] - 97;
                 ciphertext[i] = tolower(argv[1][temp2]);
             }
         }
         else
         {

             ciphertext[i] = plaintext[i];
         }
    }

    ciphertext[n] = '\0';
    printf("ciphertext: ");
    printf("%s", ciphertext);
    printf("\n");
    free(ciphertext);
    return 0;

}
