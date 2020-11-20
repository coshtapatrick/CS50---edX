// include libraries
#include<stdio.h>
#include<cs50.h>
#include<ctype.h>// isalpha()
#include <string.h>// strlen()
#include <math.h>//pow()

//announce functions
bool is_string(string word);
int to_int(string tx);

//main function
int main(int argc,string argv[])
{
    if(argc!=2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if(is_string(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = to_int(argv[1]);
    string txt = get_string("plaintext: ");
    int lntx = strlen(txt);
    for (int i=0;i<lntx;i++)
    {
        if(txt[i]>64 && txt[i]<91)
        {
            for(int j=key%26;j>0;j--)
            {
                if (txt[i]+1>90)
                {
                    txt[i]=65;
                }
                else
                {
                   txt[i]=txt[i]+1;
                }
            }
        }
        else if(txt[i]>96 && txt[i]<123)
        {
            for(int j=key%26;j>0;j--)
            {
                if (txt[i]+1>122)
                {
                    txt[i]=97;
                }
                else
                {
                   txt[i]=txt[i]+1;
                }
            }
        }
    }
    printf("ciphertext: %s\n",txt);
}


bool is_string(string word)
{
    int len= strlen(word);
    for(int i=0;i<len;i++)
    {
        if (isalpha(word[i]))
        {
            return true;
        }
    }
    return false;
}

int to_int(string tx)//makes the string in the int that it means
{
    int len= strlen(tx);//size of the string
    int number = 0;//number that will be return
    for(int i=0;i<len;i++)
    {
        int r = len-(i+1);
        number+= pow(10,i)*(tx[r]-48);//puts the number in the correct 'bit'; the 48 is a reference for the ASCII system
    }
    return number;
}
