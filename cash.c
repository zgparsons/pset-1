// Program to show the minimum number of coins needed to make the amount of change given by the user
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Getting user input
    float change;
    do
    {
        change = get_float("Change owed:  ");
    }
    while (change < 0);

    // Convert dollars to cents by *100 and round
    change = (change * 100);
    int n;
    n = round(change);
    // make caprintf ("%d\n", n);

    // Set i to zero to begin count of coins needed
    int i  = 0;
    // While loop for 25c
    while (n >= 25)
    {
        n = n - 25;
        i++;
    }
    // While loop for 10c
    while (n >= 10)
    {
        n = n - 10;
        i++;
    }
    // While loop for 5c
    while (n >= 5)
    {
        n = n - 5;
        i++;
    }
    // While loop for pennies
    while (n >= 1)
    {
        n = n - 1;
        i++;
    }
    printf("%d\n", i);
}
