// Abstraction with parameterization

#include <stdio.h>

void meow(int n);

int main(void)
{
	int n = get_int("Number of times: ");
    meow(int n);
}

// Meow some number of times
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}