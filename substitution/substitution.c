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
	bool number = alphabetical_chars (argv[1]);

	if (number == false)
	{
		return 1;
	}


	//Key can't contain two equal characters
	bool same = same_chars (argv[1]);

	if (same == false)
	{
		return 1;
	}

	//Prompt the user for the plaintext
	string plaintext = get_string("Plaintext: ");

	//Encipher the plaintext to obtain the ciphertext
	string key = argv[1];

	for (int x = 0, n = strlen(key); x < n; x++)
	{
		if (isupper(plaintext[x]))
		{
			char cipher = key[ - 97]
		}
	}


}



bool alphabetical_chars (string text)
{
	for (int z = 0, n = strlen(text); z < n; z++)
	{
		if (!isalpha(text[z]))
		{
			printf("Key must only contain alphabetical characters\n");
			return false;
		}
	}
	return true;
}



bool same_chars (string key)
{
	for (int i = 0, n = strlen(key); i < n; i++)
	{
		if ((key[i+1]) == (key[i]))
		{
			printf("Key cannot have two equal characters\n");
			return false;
		}
	}
	return true;
}