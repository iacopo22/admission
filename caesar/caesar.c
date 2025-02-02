#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int is_int(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    is_int(argv[1]);




}


int is_int(string s)
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
    printf("%i\n", x);
    return x;
}
