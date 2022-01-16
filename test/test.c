// Abstraction with parameterization

#include <stdio.h>

void meow(int n);

int main(void)
{
    void meow(int n);
}

// Meow some number of times
void meow(int n)
{
	n = get_int("Number of times: ");
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}