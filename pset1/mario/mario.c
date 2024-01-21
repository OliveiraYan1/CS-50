#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int h;

    // get the height of the pyramid from the user
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    for (int i = 1; i <= h; i++) // loop for print the number of lines that will be the height of the pyramid
    {

        for (int x = h; x > i; x--) // print spaces
        {
            printf(" ");
        }

        for (int j = 0; j < i; j++) // loop for print the number of hashes in each line of the pyramid
        {
            printf("#");
        }
        printf("\n");
    }
}
