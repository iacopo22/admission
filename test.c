#include <cs50.h>
#include <stdio.h>

int loop_elements(int i);

int main(void)

{
	int z = 0;
	z = loop_elements(z);
	int test[loop_elements(z)];
	printf ("%i\n", test[loop_elements(z)]);
}

int loop_elements(int i)
{
	i = 0;
	do
	{
		i++;
	}
	while (i < 100);
	return i;
}