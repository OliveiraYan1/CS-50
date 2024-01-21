#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // prompt for input

    long cardnumber;

    do
    {
        cardnumber = get_long("Card number: ");
    }
    while (cardnumber < 0);



    // count the numbers of input and get the first two digits

    int lenght = 2;
    int brand = 0;
    long lenght2 = cardnumber;

    while (lenght2 > 100)
    {
        lenght2 /= 10;
        lenght++;
        brand = lenght2;
    }


    //Luhn's

    //get the second-to-last digit and the others digits and multiply each number by 2


    int digits;
    int digits2;
    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int total1 = 0;
    int total;

    for(int i = 1; i < lenght; i += 2)
    {
        digits = (cardnumber/(long)pow(10, i)) % 10;
        digits *=2;

        if(digits > 9)
        {
            sum1 += digits % 10;
            sum2 += digits / 10;
        } else
        {
            sum += digits;
        }

        total1 = sum + sum1 + sum2;

    }

     for (int j = 0; j < lenght; j += 2)
        {
            digits2 = (cardnumber/(long)pow(10, j) % 10);
            sum3 += digits2;
        }


    total = total1 + sum3;


    // result

    if (total % 10 != 0 || lenght < 13)
    {
        printf("INVALID\n");
    } else
    {
        if (brand == 34 || brand == 37)
    {
        printf ("AMEX\n");
    }
    else if (brand >= 51 && brand <= 55)
    {
        printf ("MASTERCARD\n");
    }
    else if (brand / 10 == 4)
    {
        printf ("VISA\n");
    } else
    {
        printf ("INVALID\n");
    }
    }
 }
