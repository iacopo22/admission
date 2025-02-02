#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

bool is_int(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    bool integer = is_int(argv[1]);

    return 1;
}


bool is_int(string s)
{
    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if (s[i] >= 0 && s[i] <= 9)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
