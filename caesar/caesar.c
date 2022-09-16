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


	for (int z = 0, n = strlen(plaintext); z < n; z++)
	{
	char letter = rotate (plaintext[z], k);
	}



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
		//Position in the alphabetical order if the char is upper case
		c = c - 65;
		//Apply the formula
		int ascii_cypher = ((c + n) % 26);
		printf("n: %i\n", n);
		printf("Position of the char: %i\n", (int) c);
		printf("Position of the char cyphered: %i\n", ascii_cypher);

	}
	else if (islower(c))
	{
		//Position in the alphabetical order if the char is lowercase
		c = c - 97;
		//Apply the formula
		int ascii_cypher = ((c + n) % 26);
		printf("Position of the char: %i\n", (int) c);
		printf("Position of the char cyphered: %i\n", ascii_cypher);
	}
	//Position in the alphabetical order if the char is punctuation or a number (in this case remain the same according to the request)
	else if (!isalpha(c) && !islower(c) && !isupper(c))
	{
		printf("Position of the char: %i\n", (int) c);
	}
	return c;


}