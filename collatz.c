#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int collatz(int n);


int main(void)
{

    int n = 12;

    int counter = collatz(n);
    printf("Number of times: %i\n", counter);

}

int collatz(int n)
{

    //base case
    if (n == 1)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        collatz(n / 2);
    }
    else if (n % 2 != 0)
    {
        collatz((3 * n) + 1);
    }

    int counter = 0;
    while(n < 12)
    {
        counter++;
    }
    return counter;
}
