#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int collatz(int n);
int counter = 0;

int main(void)
{

    int n = get_int("Integer: ");

    int number = collatz(n);
    printf("Number of times: %i\n", number);

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
        counter++;
        collatz(n / 2);
    }
    else if (n % 2 != 0)
    {
        counter++;
        collatz((3 * n) + 1);
    }
    return counter;
}
