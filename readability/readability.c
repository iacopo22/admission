#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//I declare the functions
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
	//I want the user to prompt a string
	string text = get_string("Text: ");

	//Here the program prints the text
	printf("Text: %s\n", text);

	//I recall the function count_letters
    int length = count_letters(text);
	printf("Number of letters: %i\n", length);

	int words = count_words(text);
	printf("Number of words: %i\n", words);

	int sentences = count_sentences(text);
	printf("Number of sentences: %i\n", sentences);


	float L = (length/words) * 100.0;
	float S = (sentences/words) * 100.0;

	printf("%f\n", L);


	float index = L * 0.0588 - 0.296 * S - 15.8;
	printf("Grade: %f\n", index);



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
	int words = 1;
	for (int j = 0, n = strlen(text); j < n; j++)
	{
		if (text[j] == 32)
		{
			words++;
		}
	}
	return words;
}

int count_sentences(string text)
{
	int sentences = 0;
	for (int k = 0, n = strlen(text); k < n; k++)
	{
		if (text[k] == 46 || text[k] == 63 || text[k] == 33 || text[k] == 34)
		{
			sentences++;
		}
	}
	return sentences;
}








