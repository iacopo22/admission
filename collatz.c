#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int collatz(int n);


int main(void)
{

    int n = 4;

    collatz(n);

}

int collatz(int n)
{
     if (n == 1)
     {
           return 1;
     }
     else if (n % 2 == 0)
     {
          return collatz(n/2);
     }
     else if (n % 2 != 0)
     {
          return collatz((3 * n) + 1);
     }


}
