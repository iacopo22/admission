#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool repetition(string s);
bool is_char(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    bool alpha = is_char(argv[1]);

    if (alpha == false)
    {
        printf("Only letters!\n");
        return 1;
    }

    bool repetition_ = repetition(argv[1]);

    if (repetition_ == false)
    {
        printf("Letters have to be different from each others\n");
        return 1;
    }

    // Prompt the user for the plaintext
    string plaintext = get_string("Plaintext: ");





}

bool is_char(string s)
{
    for(int i = 0, length = strlen(s); i < length; i++)
    {
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
        for (int j = i; j < length; j++)
        {
            if (i != j && s[i] == s[j])
            {
                return false;
            }
        }
    }
    return true;
}


char cypher(string p, string k)
{
    for(int i = 0, length = strlen(p); i < length; i++)
    {
        if (isupper(p[i])
        {
            char cypher_up = k[p[i] - 65];
            return cypher_up;
        }
        else if (islower(p[i]))
        {
            char cypher_low = k[p[i] - 65];
            return cypher_low;
        }
    }
}
