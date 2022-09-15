#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//I declare the functions
int count_letters(string text);
int count_words(string text);

int main(void)
{
	//I want the user to prompt a string
	string text = get_string("Text: ");

	//Here the program prints the text
	printf("Text: %s\n", text);

	//I recall the function count_letters
    int length = count_letters(text);
	printf("Length: %i\n", length);

	int words = count_words(text);
	printf("Number of words: %i\n", words);


}

//I define the function
int count_letters(string text)
{
	//Whole length
	int length = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
		//Conditions to avod numbers, symbols and spaces
		if (isalpha(text[i]))
		{
			length ++;
		}
    }
	return length;
}


int count_words(string text)
{

	int words = 0;
	for (int j = 0, n = strlen(text); j < n; j++)
	{
		if (isalpha(text[0]))
		{
			if (text[j] == 32)
			{
				words++;
			}
		}
		else ((int) text[0] == 32)
		{
			return 1;
		}
	}


}




}
