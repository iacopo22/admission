#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1] != 26)
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



}

bool is_char(string s)
{
    for(int i = 0, length = strlen(s); i < length; i++)
    {
        if (!isalpha(s[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

bool repetition(string s)
{
    int length = strlen(s)

    for (int i = 0; i < length; i++)
    {
        for (int j = 1; j < length - 1; j++)
        {
            if (s[i] == s[j])
            {
                return false;
            }
        }
    }
    return true;
}
