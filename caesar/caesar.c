#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s);

int main(int argc, string argv[])
{

	//If there aren't input or if there are more then one, the program prints an error
	if (argv[1] == NULL || argv[2] != NULL)
	{
		printf("Usage: ./caesar key\n");
	}
	return 1;

	//The input has to be greater and equal to 0 and smaller than 10
	bool x = only_digits(argv[1]);

	if (x == false)
	{
		printf("Usage: ./caesar key\n");
	}
	else
	{
		return 1;
	}


}


bool only_digits(string s)
{
	for (int i = 0, n = strlen(s); i < n; i++)
	{
		if (!isdigit(s[i]))
		{

		}
		else
		{
			return false;
		}
	}
	return true;
}