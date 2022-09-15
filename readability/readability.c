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

	//I recall the function count_letters
    int length = count_letters(text);

	//I recall the function count_words
	int words = count_words(text);


	//I recall the function count_sentences
	int sentences = count_sentences(text);

	//Elements of Coleman-Liau index
	float L = ((float) length / (float) words) * 100;
	float S = ((float) sentences / (float) words) * 100;

	//Coleman-Liau index
	double index = L * 0.0588 - 0.296 * S - 15.8;

	//Conditions of grade greater or equal than 16 or smaller than 1
	if (index >= 16)
	{
		printf("Grade 16+\n");
	}
	else if (index < 1)
	{
		printf("Before Grade 1\n");
	}
	else if (1 <= index && index < 16)
	{
		printf("Grade %d\n", (int) round(index));
	}



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
		if (text[k] == 46 || text[k] == 63 || text[k] == 33)
		{
			sentences++;
		}
	}
	return sentences;
}








