#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        char char_cyphered = rotate(plaintext[i], key);
        printf("%c", char_cyphered);
    }
    printf("\n");



}


bool is_int(string s)
{
    int length = strlen(s);
    bool x;

    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            x = true;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return x;
}

char rotate(char c, int k)
{
    char cyph = (c + k) % 26;

    printf("%c\n", cyph);

    return cyph;

}
