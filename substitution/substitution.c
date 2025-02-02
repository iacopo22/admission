#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool repetition(string s);
bool is_char(string s);
char cypher(char p, string k);

int main(int argc, string argv[])
{
    // If the number of arguments is not 2 then stop the program
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // If the number of letters in the key is not 26 then stop the program
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Store the boolean value in alpha
    bool alpha = is_char(argv[1]);

    // Check if there are only letters
    if (alpha == false)
    {
        printf("Only letters!\n");
        return 1;
    }

    bool repetition_ = repetition(argv[1]);

    // Check for repetitions
    if (repetition_ == false)
    {
        printf("Letters have to be different from each others\n");
        return 1;
    }

    // Prompt the user for the plaintext
    string plaintext = get_string("Plaintext: ");

    printf("ciphertext: ");

    // Cypher every char throught the function "cypher"
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        char cyphered = cypher(plaintext[i], argv[1]);
        printf("%c", cyphered);
    }
    printf("\n");
}

bool is_char(string s)
{
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        // Check if the char in the key is a letter
        if (!isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool repetition(string s)
{
    int length = strlen(s);

    for (int i = 0; i < length - 1; i++)
    {
        // Every char is compared with the following ones
        for (int j = i + 1; j < length; j++)
        {
            // To upper because I can have the same letter but
            // in uppercase and in lowercase
            if (toupper(s[i]) == toupper(s[j]))
            {
                return false;
            }
        }
    }
    return true;
}

char cypher(char p, string k)
{
    if (isupper(p))
    {
        // letter A is associated with the first element in the key, so k[0]
        char cypher_up = toupper(k[p - 65]);
        return cypher_up;
    }
    else if (islower(p))
    {
        char cypher_low = tolower(k[p - 97]);
        return cypher_low;
    }
    else if (!isalpha(p))
    {
        return p;
    }
    return 0;
}
