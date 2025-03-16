// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"


int counter = 0;
bool loaded;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26*26;

// Hash table
node *table[N];

void print_buckets(void)
{
    unsigned long sum_sq = 0;
    int num_words = (int)size();

    // use dynamic memory allocation instead of the stack for these arrays,
    // in order to prevent a possible stack overflow
    int *collisionCount = calloc(num_words, sizeof *collisionCount);
    int *bucketCounter  = calloc(N, sizeof *bucketCounter);
    if (bucketCounter == NULL || collisionCount == NULL)
    {
        printf("Memory allocation error!\n");
        exit(EXIT_FAILURE);
    }

    // fill bucketCounter array
    for (int i = 0; i < N; i++)
    {
        for (node *p = table[i]; p != NULL; p = p->next)
        {
            bucketCounter[i]++;
        }
    }

    // fill collisionCount array
    for (int i = 0; i < N; i++)
    {
        collisionCount[bucketCounter[i]]++;
    }

    // print content of collisionCount array and update sum_sq
    for (int i = 0; i < num_words; i++)
    {
        if (collisionCount[i])
        {
            sum_sq += (long) i * i * collisionCount[i];
            printf("Buckets with %i nodes: %i\n", i, collisionCount[i]);
        }
    }

    // print final information
    printf("\n");
    printf("Sum  of squares: %lu\n",  sum_sq);
    printf("Mean of squares: %.3f\n", (double)sum_sq / num_words);

    // Exit the program prematurely, so that you can see the diagnostic output
    // instead of the misspelled words. Exiting prematurely will cause memory leaks,
    // so don't run this function with valgrind.
    exit(EXIT_SUCCESS);
}








// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word);
    int check = 0;
    node *cursor = table[index];

    while(cursor != NULL)
    {
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
    // Sort based on the first two letters
    if(strlen(word) < 2)
    {
        return toupper(word[0]) - 'A';
    }
    else
    {
        // Le stesse lettere in ordine diverso danno lo stesso risultato
        return toupper(word[0]) - 'A' + toupper(word[1]) - 'A';
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
    {
        printf("Could not open the file\n");
        return 1;
    }

    char word[LENGTH + 1];
    unsigned int index = 0;

    while(fscanf(dict, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            return 1;
        }

        strcpy(n->word, word);
        n->next = NULL;

        index = hash(word);

        n->next = table[index];
        table[index] = n;

        counter++;
    }

    fclose(dict);
    loaded = true;
    // print_buckets();
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (loaded == true)
        return counter;
    else
        return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *cursor = NULL;
    node *tmp = NULL;

    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        tmp = cursor;
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
