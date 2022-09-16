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
	if (argc != 2 )
	{
		printf("Error\n");
		return 1;
	}


	//The input has to be a number or a digit, so it checks all of the chars of the string
	only_digits(argv[1]);

	//The key to encrypt the plaintext
    int k = atoi(argv[1]);

	//The plaintext prompted from the user
	string plaintext = get_string("Plaintext: ");

	printf("ciphertext: ");

	for (int z = 0, n = strlen(plaintext); z < n; z++)
	{
	char letter_cyphered = rotate (plaintext[z], k);
	printf("%c", letter_cyphered);
	}
	printf("\n");

}


bool only_digits (string s)
{
	for (int i = 0, n = strlen(s); i < n; i++)
	{
		if (!isdigit(s[i]))
		{
			printf("Usage: ./caesar key\n");
			return 1;
		}
	}
	return 0;
	printf("Cavallo");
}


char rotate (char c, int n)
{

	if (isupper(c))
	{
		//Position in the alphabetical order if the char is upper case
		c = c - 65;
		//Apply the formula
		int pos_cyphered = ((c + n) % 26) + 65;
		return pos_cyphered;
	}
	else if (islower(c))
	{
		//Position in the alphabetical order if the char is lowercase
		c = c - 97;
		//Apply the formula
		int pos_cyphered = ((c + n) % 26) + 97;
		return pos_cyphered;
	}
	//Position in the alphabetical order if the char is punctuation or a number (in this case remain the same according to the request)
	else if (!isalpha(c) && !islower(c) && !isupper(c))
	{
		return c;
	}
	return 0;

}