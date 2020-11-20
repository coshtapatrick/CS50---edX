#include <stdio.h>
#include <cs50.h>

int main(void)
{
    while (true)
    {
        int cents = 1000*get_float("Change owed:");
        if (cents>0)
        {
            int coins = 0;
            coins += cents/250;
            cents=cents%250;
            coins += cents/100;
            cents=cents%100;
            coins += cents/50;
            cents=cents%50;
            coins += cents/10;
            printf("%i\n",coins);
            break;
        }
    }
}
