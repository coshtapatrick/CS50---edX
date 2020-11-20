// Made By PMBC
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card = get_long("Number: ");
    string card_type = "INVALID";
    int t = 0;
    for(int i=15;i>=0;i--)
    {
        long n=1;
        for(int x=0;x<i;x++)
        {
            n = n*10;
        }
        int dig = card/n;
        card = card%n;
        if (i%2==1){if(dig*2>9){t+=1;t+=(dig*2)%10;}else{t+=dig*2;}}
        else{t+=dig;}
        if (i==15 && dig==5)
        {
            long n2=n/10;
            if(card/n2>0 && card/n2<6){card_type="MASTERCARD";}
        }
        else if (i==15 && dig == 4){card_type="VISA";}
        else if (i==12 && dig == 4){card_type="VISA";}
        else if (i==14 && dig == 3)
        {
            long n2=n/10;
            if(card/n2==4 || card/n2==7){card_type="AMEX";}
        }
    }
    if (t%10!=0){card_type="INVALID";}
    printf("%s\n",card_type);
}
