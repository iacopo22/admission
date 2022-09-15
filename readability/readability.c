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
	count_letters(text);

}

//I define the function
int count_letters(string text)
{
	int n = 0;
	for (int i = 0, n = strlen(text); i < n; i++)
	{
		n++;
	}
	retur n;
}
