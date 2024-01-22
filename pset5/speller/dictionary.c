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

// Number of buckets in hash table
#define N 26

// Hash table
node *table[N];

// Declaring variables
unsigned int hash_value;
unsigned int word_count;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Set in a cursor
    node *cursor;

    // Hash word to obtain hash value
    hash_value = hash(word);

    // Access linked list at that index in the hash table
    cursor = table[hash_value];

    // Loop over the bucket that cursor is pointing.
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int total = 0;

    // Iterate through each character of the input word until the null terminator is encountered
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Update the total using the djb2 hash algorithm:
        total = 31 * total + tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");

    // Scan dictionary
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory to a new node
        node *n = malloc(sizeof(node));

        // Check for NULL
        if (n == NULL)
        {
            return false;
        }

        // Copy strings to n->word
        strcpy(n->word, word);

        // Hash word to obtain a hash value
        hash_value = hash(word);

        // Insert node into a hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Set in a cursor
    node *cursor;

    // Set in a temporary variable
    node *tmp;

    // Loop to free memory
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
