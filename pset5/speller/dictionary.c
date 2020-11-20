// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"
#define LENGHT 45

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = (LENGHT + 1);

//Global variable that counts the total words
int words_counter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int index = hash(word);

    node *pointer = table[index];

    while (pointer != NULL)
    {
        if (strcasecmp(pointer->word, word) == 0)
        {
            return true;
        }
        pointer = pointer->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    char word[LENGHT + 1];
    while (fscanf(dict, "%s", word) != EOF)
    {
        node *n_node = malloc(sizeof(node));
        if (n_node == NULL)
        {
            return false;
        }
        strcpy(n_node->word, word);
        n_node->next = NULL;

        int index = hash(word);
        if (table[index] == NULL)
        {
            table[index] = n_node;
        }
        else
        {
            n_node->next = table[index];
            table[index] = n_node;
        }
        words_counter++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return words_counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *pointer = head;
        node *tmp = pointer;

        while (pointer != NULL)
        {
            pointer = pointer->next ;
            free(tmp);
            tmp = pointer;
        }
    }
    return true;
}
