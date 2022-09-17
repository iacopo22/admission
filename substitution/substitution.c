#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool chars_argv (string text);

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
	}

	//Key must only contain alphabetical characters
	chars_argv (argv[1]);


	string plaintext = get_string("Plaintext: ");



}



bool chars_argv (string text)
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