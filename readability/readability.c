#include <cs50.h>
#include <stdio.h>
#include <string.h>

//I declare the function
int count_letters(string text);

int main(void)
{
	//I want the user to prompt a string, not numbers or symbols
	string text = get_string("Text: ");

	//Here the program prints the text
	printf("Text: %s\n", text);

	//I recall the function count_letters
	int length = count_letters(text[words]);
	printf("Number of characters: %i\n", length);

}

//I define the function
int count_letters(int n_words, string text[])
{
	for (int i = 0; i < n_words; i++)
	{
		for (int j = 0; j < strlen(text[i]); j++)
		{
			printf("%i", text[i][j]);
		}
		printf("\n");
	}
}
