#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int collatz(int n);


int main(void)
{
    int counter = 0;

    int n = 12;

    collatz(n);

    counter++;


    printf("Number of times: %i\n", counter);

    return 0;
}

int collatz(int n)
{
     if (n == 1)
     {
           return 1;
     }
     else if (n % 2 == 0)
     {
          return n/2;
     }
     else if (n % 2 != 0)
     {
          return (3 * n) + 1;
     }
     return n;
}
