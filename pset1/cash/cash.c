#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{

    float user;
    int t = 100;
    int quarters = 25;
    int tens = 10;
    int nikels = 5;
    int penneys = 1;
    int cents;

    // get the user input

    do
    {
        user = get_float("Change owed:");
    }
    while (user < 0);

    // convert input to cents

    cents = round(user * t);

    // count the quarters and get quarter's modulus

    int cquarters;
    int modquarters;

    cquarters = floor(cents / quarters);
    modquarters = cents % quarters;

    // count the tens and get ten's modulus

    int ctens;
    int modtens;

    ctens = floor(modquarters / tens);
    modtens = modquarters % tens;

    // count nikels and get nikels's modulus

    int cnikels;
    int modnikels;

    cnikels = floor(modtens / nikels);
    modnikels = modtens % nikels;

    // count penneys

    int cpenneys;
    int modpenneys;

    cpenneys = floor(modnikels / penneys);

    // total of coins that's used to

    printf("%d\n", cquarters + ctens + cnikels + cpenneys);
}
