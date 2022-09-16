#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);

int main(int argc, string argv[])
{

	//If there aren't input or if there are more then one, the program prints an error
	if (argc != 1)
	{
		printf("Usage: ./caesar key\n");
		return 0;
	}


	//The input has to be a number or a digit, so it checks all of the chars of the string
	only_digits(argv[1]);


	for (int j = 0, n = strlen(argv[1]); j < n; j++)
	{
	int number(string argv[j]);
	printf("Number: %i\n", number)
	}



	//If the k is greater than 26, the program should convert the letter in another letter following alphabetical order (check ASCII)


}


bool only_digits(string s)
{
	for (int i = 0, n = strlen(s); i < n; i++)
	{
		if (isdigit(s[i]))
		{
			continue;
		}
		else
		{
			printf("Usage: ./caesar key\n");
			return false;
		}
	}
	return true;
}