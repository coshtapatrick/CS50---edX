// include libraries
#include <stdio.h>
#include <cs50.h>
#include <string.h> // strlen()
#include <ctype.h> // isalpha()
#include <math.h>// round()

//announcing functions
int count_letters(string txt);
bool isin(char c, char ref[]);
int count_words(string txt);
int count_sentences(string txt);

int main(void)
{
    string text = get_string("Text: ");//ask for the text to be analyzed
    int lts = count_letters(text); // count the amount of letters in text
    float wrd = count_words(text);// count the amount of word in text
    int stc = count_sentences(text);// count the amount of sentences in text
    float L = (lts/wrd)*100;
    float S = (stc/wrd)*100;
    float index = 0.0588*L - 0.296*S - 15.8;
    int i = round(index);
    if (i <1)
    {
        printf("Before Grade 1\n");
    }
    else if (i>=16)
    {
        printf("Grade 16+\n");

    }
    else
    {
        printf("Grade %i\n",i);
    }

}

int count_sentences(string txt)
{
    int len = strlen(txt);// measure the size of the text
    int stc = 0;// count each sentence
    char separators[]={'.','!','?'};
    for(int i = 0; i<len;i++)
    {
        if (isin(txt[i],separators))
        {
            stc++;
        }
    }
    return stc;
}

int count_words(string txt)
{
    int len = strlen(txt);// measure the size of the text
    int words = 0;// count each word
    char separators[]={' '};
    for(int i = 0; i<len;i++)
    {
        if (isin(txt[i],separators))
        {
            words++;
        }
    }
    words++;
    return words;
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

int count_letters(string txt)
{
    int len = strlen(txt);// measure the size of the text
    int lts = 0;
    for(int i = 0; i<len;i++)
    {
        if (isalpha(txt[i]))
        {
            lts++;
        }
    }
    return lts;
}
