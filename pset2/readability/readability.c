#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    // get input from the user.
    string Text = get_string("Text: ");

    int letters = 0;

    // count the uppercase letters and lowercase letters

    for (int i = 0, n = strlen(Text); i < n; i++)
    {
        if (isalpha(Text[i]) != 0)
        {
            letters++;
        }
    }

    // counting the words in a sentence (number of spaces + 1)

    int words = 1;

    for (int i = 0, n = strlen(Text); i < n; i++)
    {
        if (isspace(Text[i]) != 0)
        {
            words++;
        }
    }

    // counting sentences

    int sentences = 0;

    for (int i = 0, n = strlen(Text); i < n; i++)
    {
        if (Text[i] == '.' || Text[i] == '!' || Text[i] == '?')
        {
            sentences++;
        }
    }

    // Coleman Liau index

    float L;
    float S;
    float index;

    // Calculate L

    L = (letters / (float) words) * 100;

    // Calculate S

    S = (sentences / (float) words) * 100;

    index = round(0.0588 * L - 0.296 * S - 15.8);

    // print the result

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int) index);
    }
}
