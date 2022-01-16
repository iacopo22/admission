// Counting

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int i = 0;
    while (true)
    {
        printf("%i\n", i);
        i--;
		sleep(1);
    }
}