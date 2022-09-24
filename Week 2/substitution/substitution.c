#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool alphabetical_chars(string text);
bool same_chars(string key);
char cyphertext(string k, char plain);

int main(int argc, string argv[])
{
    //Two argument lines
    if (argc != 2)
    {
        printf("Error: the program requires two argument lines\n");
        return 1;
    }

    //Key must contain 26 characters
    int j = 0;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        j++;
    }
    if (j != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    //Key must only contain alphabetical characters
    bool number = alphabetical_chars(argv[1]);

    if (!alphabetical_chars(argv[1]))
    {
        return 1;
    }

    //Key can't contain two equal characters
    bool same = same_chars(argv[1]);

    if (!same_chars(argv[1]))
    {
        return 1;
    }

    //Prompt the user for the plaintext
    string plaintext = get_string("plaintext: ");

    //Encipher the plaintext to obtain the ciphertext
    string key = argv[1];

    printf("ciphertext: ");

    for (int x = 0, n = strlen(plaintext); x < n; x++)
    {
        char letter_ciphered = cyphertext(key, plaintext[x]);
        printf("%c", letter_ciphered);
    }

    printf("\n");
    return 0;
}

bool alphabetical_chars(string text)
{
    for (int z = 0; z < strlen(text); z++)
    {
        if (!isalpha(text[z]))
        {
            printf("Key must only contain alphabetical characters\n");
            return false;
        }
    }
    return true;
}

bool same_chars(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if ((key[i + 1]) == (key[i]))
        {
            printf("Key cannot have two equal characters\n");
            return false;
        }
    }
    return true;
}

//Function used to encipher the plaintext (k stands for key)
char cyphertext(string k, char plain)
{
    //If the input is uppercase
    if (isupper(plain))
    {
        //I assign to the char the (plain-65)th position of the key, e.g A - 65 = 0, so the first position of the key (in the array)
        char upper_cipher = k[plain - 65];
        return toupper(upper_cipher);
    }
    //The same here, but the opposite
    else if (islower(plain))
    {
        char lower_cipher = k[plain - 97];
        return tolower(lower_cipher);
    }
    //If the char of the plaintext is not a letter I return it as it is
    else if (!isalpha(plain))
    {
        return plain;
    }
    return 0;
}