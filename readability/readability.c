#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//I declare the function
void count_letters(string text);

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
void count_letters(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        printf("%c", text[i]);
		printf("Lenght: %i", n);
    }
	printf("\n");


}
