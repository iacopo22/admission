#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return 1;
	}
	int j = 0;
	for (int i = 0, n = strlen(argv[1]); i < n; i++)
	{
		char caso[i] = argv[1];
		j++;
	}
	if (j != 26)
	{
		printf("Key must contain 26 characters\n");
	}
}