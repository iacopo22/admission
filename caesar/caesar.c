#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_int(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    // If the number of arguments is not 2 then return 1
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Store the boolean value in the variable is_integer
    bool is_integer = is_int(argv[1]);

    // If is not an integer then return 1
    if (is_integer == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert the string key in number
    int key = atoi(argv[1]);

    // Prompt the user for plaintext
    string plaintext = get_string("Plaintext: ");

    printf("ciphertext: ");

    // Loop every char to cypher the text
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        // Recall the function rotate to cypher the text, assigning the cyphered char
        // to the variable
        char char_cyphered = rotate(plaintext[i], key);
        // Print the cyphered text
        printf("%c", char_cyphered);
    }
    printf("\n");
}

bool is_int(string s)
{
    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        // Check if it's a digit otherwise return an error
        if (!isdigit(s[i]))
        {
            printf("Usage: ./caesar key\n");
            return false;
        }
    }
    return true;
}

char rotate(char c, int k)
{
    if (islower(c))
    {
        // Remove the ASCII number from the plaintext and then use the formula
        // After that, add the ASCII to find the ASCII of the cyphered char
        char cyph_low = (c - 97 + k) % 26 + 97;
        return cyph_low;
    }
    else if (isupper(c))
    {
        char cyph_up = (c - 65 + k) % 26 + 65;
        return cyph_up;
    }
    else if (!isalpha(c))
    {
        return c;
    }
    return 0;
}
