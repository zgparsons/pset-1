// Program to create a full-pyramid using hashes for blocks with x2 spaces between, based on the user's height input.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Getting user input
    int h;
    do
    {
        h = get_int("Height:  ");
    }
    while (h < 0 || h > 23);

    // Creating pyramid with input
    // Initialising for loop and setting i = 0
    for (int i = 0; i < h; i++)
    {
        // print spaces for left pyramid
        for (int spc = h - i; spc > 1; spc--)
        {
            printf(" ");
        }
        // print hashes for the left pyramid
        for (int hsh = 0; hsh < i + 1; hsh++)
        {
            printf("#");
        }
        // print spaces for gap
        {
            printf("  ");
        }
        // print hashes for right pyramid
        for (int rhsh = 0; rhsh < i + 1; rhsh++)
        {
            printf("#");
        }
        // print new line
        printf("\n");
    }
}
