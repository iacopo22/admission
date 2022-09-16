#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char plaintext, int k);

int main(int argc, string argv[])
{

	//If there aren't input or if there are more then one, the program prints an error
	if (argc != 2)
	{
		printf("Usage: ./caesar key\n");
		return 0;
	}


	//The input has to be a number or a digit, so it checks all of the chars of the string
	only_digits(argv[1]);

	//The key to encrypt the plaintext
    int k = atoi(argv[1]);

	//The plaintext prompted from the user
	string plaintext = get_string("Plaintext: ");


	char letter = rotate (plaintext[3], k);
	printf("Boh: %c\n", letter);



	//If the k is greater than 26, the program should convert the letter in another letter following alphabetical order (check ASCII)


}


bool only_digits (string s)
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






char rotate (char c, int n)
{
	if (isupper(c))
	{
		c = c - 65;
		printf("Position of the char: %i\n", (int) c);
	}
	return c;

}