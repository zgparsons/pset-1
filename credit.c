// Program to show the user if the card no. they entered is valid, and which credit card company they use
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Getting user input
    long long card;
    do
    {
        card = get_long_long("Number:  ");
    }
    while (card < 0);

    // Check card is valid
    // American Express uses 15-digit numbers,
    // MasterCard uses 16-digit numbers,
    // Visa uses 13- and 16-digit numbers.
    // American Express numbers all start with 34 or 37;
    // MasterCard numbers start with 51, 52, 53, 54, or 55
    // Visa numbers all start with 4

    // Find out length of card
    int count = 0;
    long long validate = card;

    while (validate > 0)
    {
        validate /= 10;
        count++;
    }

    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
    }

    // Begin Luhn's Algorithm

    int evenDigit;
    int oddDigit;
    int total = 0;

    validate = card;

    while (validate > 0)
    {
        evenDigit = (validate % 100) / 10;
        oddDigit = (validate % 10);
        validate /= 100;

        // add digits of multiplication of evenDigit by 2
        evenDigit *= 2;
        if (evenDigit / 10 == 1)
        {
            total += 1;
            total += evenDigit % 10;
        }
        else
        {
            total += evenDigit;
        }

        total += oddDigit;
    }

    if (total % 10 == 0)
    {
        // Determine which type of valid card it is
        if ((card >= 340000000000000 && card < 350000000000000) || (card >= 370000000000000 && card < 380000000000000))
        {
            printf("AMEX\n");
        }

        else if (card >= 5100000000000000 && card < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }

        else if ((card >= 4000000000000 && card < 5000000000000) || (card >= 4000000000000000 && card < 5000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else

    {
        printf("INVALID\n");
    }

}
