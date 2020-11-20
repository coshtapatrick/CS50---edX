// First problem of CS50 edX course
// Also: my first-ever program in C
// The porpouse of this is to count how many coins will be given to the client as change

#include <stdio.h>
#include <cs50.h> // Special Library from the course cs50, responsible for the get_float() funciton

int main(void)
{
    while (true)
    {
        int cents = 1000 * get_float("Change owed:"); // takes the value in float that has to be 
        if (cents > 0) // verifies if the inputed value is valid
        {
            // the store only has coins of 25, 10, 5 and 1 cents
            // creates a var that holds the total of coins
            int coins = 0;

            coins += cents / 250; // adds to 'coins' a int amount of "25 cents" coins
            cents = cents % 250; // keeps whats left

            // do the same for the "10 cents" coins
            coins += cents / 100;
            cents = cents % 100;

            // repeat for the "5"
            coins += cents / 50;
            cents = cents % 50;

            // whats is the change in 1's 
            coins += cents / 10;

            // prints the result: total count of coins
            printf("%i\n", coins);
            break;
        }
    }
}
