#include <cs50.h>
#include <stdio.h>
#include <string.h>

//I declare the function
int count_letters(int n_words, string text[]);

int main(void)
{
	//I want the user to prompt a string, not numbers or symbols
	string text = get_string("Text: ");

	//Here the program prints the text
	printf("Text: %s\n", text);

	//I recall the function count_letters
	int length = count_letters(text[]);
	printf("Number of characters: %i\n", length);

}

//I define the function
int count_letters(string text[])
{
	for (int i = 0; i < n_words; i++)
	{

	}
}
