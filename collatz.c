#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int collatz(int n);


int main(void)
{

    int n = 4;

    int counter = collatz(n);
    printf("Number of times: %i\n", counter);

}

int collatz(int n)
{
    int counter = 0;
    if (n == 1)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        counter++;
        return collatz(n/2);
    }
    else if (n % 2 != 0)
    {
        counter++;
        return collatz((3 * n) + 1);
    }
    return counter;
}
