// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
#define N 26

// Hash table
node *table[N]; // Hash table

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *n = table[index];
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash += tolower(word[i]);
        hash += hash * 31;
    }
    return hash % N;
}
// Adds word to dictionary
bool add(const char *word)
{
    unsigned int index = hash(word);
    node *tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
        return false;
    }
    strcpy(tmp->word, word);
    tmp->next = NULL;
    node *n = table[index];
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            free(tmp);
            return false;
        }
        n = n->next;
    }
    tmp->next = table[index];
    table[index] = tmp;
    return true;
}
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) == 1)
    {
        if (add(word) == false)
        {
            return false;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        while (n != NULL)
        {
            count++;
            n = n->next;
        }
    }
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        while (n != NULL)
        {
            node *next = n->next;
            free(n);
            n = next;
        }
    }
    return true;
}
