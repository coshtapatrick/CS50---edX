// include libraries
#include<stdio.h>
#include<cs50.h>
#include<ctype.h>// isalpha() tolower()
#include <string.h>// strlen() strchr() strrchr()
#include <math.h>//pow()

//announce functions
bool is_str(string word);
int to_int(string tx);
bool uniquestr(string txt);
bool isin(char c, char ref[]);
string tolows(string txt);

//main function
int main(int argc,string argv[])
{
    if(argc==2 && is_str(argv[1]) && strlen(argv[1])==26)
    {
        string key = tolows(argv[1]);
        if (uniquestr(key))
        {
            printf("Wrong Usage\n");
            return 1;
        }
//main line when the key is okay to go-------------
        string txt = get_string("plaintext: ");
        for (int i=0;i<strlen(txt);i++)
        {
            if(txt[i]>96 && txt[i]<123)
            {
                int ind = txt[i]-97;
                txt[i]=key[ind];
            }
            if(txt[i]>64 && txt[i]<91)
            {
                int ind = txt[i]-65;
                txt[i]=toupper(key[ind]);
            }
        }
        
        printf("ciphertext: %s\n",txt);
    }
    else
    {
        printf("Wrong Usage\n");
        return 1;
    }
}

string tolows(string txt)
{
   for(int i=0;i<strlen(txt);i++)
    {
        txt[i]=tolower(txt[i]);
    }
    return txt;
}
bool uniquestr(string txt)
{
    int len= strlen(txt);
    for(int i=0;i<len;i++)
    {
        if(strchr(txt,txt[i])!=strrchr(txt,txt[i]))
        {
            return true;
        }
    }
    return false;
}

bool isin(char c, char ref[])
{
    int len= strlen(ref);
    for(int i=0;i<len;i++)
    {
        if (c==ref[i])
        {
            return true;
        }
    }
    return false;
}

bool is_str(string word)//verifies if all the elements are alphabetic characters
{
    int len= strlen(word);
    for(int i=0;i<len;i++)
    {
        if (isdigit(word[i]))
        {
            return false;
        }
    }
    return true;
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
