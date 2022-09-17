#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return 1;
	}

	for (int i = 0, n = strlen(argv[1]); i < n; i++)
	{
		printf("Length: %i\n", i);
	}
}