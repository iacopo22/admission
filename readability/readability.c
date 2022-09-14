#include <cs50.h>
#include <stdio.h>

//I declare the function
int count_letters(string text);

int main(void)
{
	//I want the user to prompt a string, not numbers or symbols
	string text = get_string("Text: ");


	//Here the program prints the text
	printf("Text: %s\n", text);

	//I recall the function count_letters
	int count_letters(string text);
	printf("Number of letters: %i\n", count_letters);

}

//I define the function
int count_letters(string text)
{

}