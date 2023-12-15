#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long cardNumber = get_long("Card number: ");
    //AMEX = 34xxxxxxxxxxxxx, 37xxxxxxxxxxxxx
    //Mastercard = 5xxxxxxxxxxxxxxx
    //Visa = 4xxxxxxxxxxxxxxx

    if (cardNumber >= 340000000000000 && cardNumber < 350000000000000 || cardNumber >= 370000000000000 && cardNumber < 380000000000000)
    {
        printf("AMEX\n");
    }

    else if (cardNumber >= 5000000000000000 && cardNumber < 6000000000000000)
    {
        printf("Mastercard\n");
    }

    else if (cardNumber >= 4000000000000000 && cardNumber < 5000000000000000)
    {
        printf("Visa\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
