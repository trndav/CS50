// Program requires other non existing files to run from Problem set of week 5. Saved here for testing an backup.

// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdbool.h>
#include <stddef.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    // Construct the full path to the dictionary file
    char path[100];
    snprintf(path, sizeof(path), "%s", dictionary);

    printf("Attempting to open file: %s\n", path);

    FILE *dict = fopen(path, "r");
    if (dict == NULL)
    {
        printf("Could not open file or there is no file.\n");
        return false;
    }
    char readword[LENGTH + 1];
    while (fscanf(dict, "%s", readword) != EOF)
    {
        // Allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(dict);
            return false;
        }
        // Copy the word into the new node
        strcpy(n->word, readword);

        // Hash the word to obtain its hash value
        int hash_value = hash(n->word);

        // Insert the new node into the hash table
        n->next = table[hash_value];
        table[hash_value] = n;
    }

    fclose(dict);
    return true;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hash_value = hash(word);
    node *cursor = table[hash_value];
    // Search for the word in the linked list
    while (cursor != NULL)
    {
        // Compare case-insensitively using strcasecmp
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 0;
    // Sum ASCII of all characters in the word
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value += (unsigned int)word[i];
    }
    // Modulo to keep the hash within a reasonable range
    return hash_value % N;
    //return toupper(word[0]) - 'A';
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
        unsigned int word_count = 0;
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            word_count++;
            cursor = cursor->next;
        }
    }
    return word_count;
    //return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
      for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            // Keep a reference to the current node
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        // Set the table index to NULL after freeing all nodes
        table[i] = NULL;
    }
    return true;
}
