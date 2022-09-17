#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool alphabetical_chars (string text);
bool same_chars (string key);

int main(int argc, string argv[])
{
	//Two argument lines
	if (argc != 2)
	{
		printf("Error: the program requires two argument lines\n");
		return 1;
	}

	//Key must contain 26 characters
	int j = 0;
	for (int i = 0, n = strlen(argv[1]); i < n; i++)
	{
		j++;
	}
	if (j != 26)
	{
		printf("Key must contain 26 characters\n");
		return 1;
	}

	//Key must only contain alphabetical characters
	alphabetical_chars (argv[1]);


	//Key can't contain two equal characters
	same_chars (argv[1]);


	string plaintext = get_string("Plaintext: ");


	for (int y = 0, m = strlen(plaintext); y < m; y++)
	{
		printf("Char of the plaintext: %c\n", plaintext[y]);
	}



}



bool alphabetical_chars (string text)
{
	for (int z = 0, n = strlen(text); z < n; z++)
	{
		if (!isalpha(text[z]))
		{
			printf("Key must only contain alphabetical characters\n");
		}
	}
	return 1;
}

bool same_chars (string key)
{
	for (int h = 0, n = strlen(key); h < n; h++)
	{
		if ((text[h]))
		{
			
			printf("Key can't contain two equal characters\n");
		}
	}
}