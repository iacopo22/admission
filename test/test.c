// Counting

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int i = 0;
    while (i < 3)
    {
        printf("\r%i", i);
        i++;
    }
}