#include <stdio.h>
#include <cs50.h>

int main (void)
{
    while (true)
    {
        int hgt = get_int("Height:");
        if (hgt>0 && hgt <9)
        {
            for(int i=1;i<=hgt;i++)
            {
                for(int j=i; j<hgt; j++){printf(" ");}
                for(int x=0; x<i;x++){printf("#");}
                printf("  ");
                for(int x=0; x<i;x++){printf("#");}
                printf("\n");
            }
            break;
        }
    }
}
