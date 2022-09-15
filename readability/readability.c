#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//I declare the function


int main(void)
{
	//I want the user to prompt a string, not numbers or symbols
	string text = get_string("Text: ");

	//Here the program prints the text
	printf("Text: %s\n", text);

	//I recall the function count_letters
    int length = strlen(text);
	printf("Length: %i\n", length);


}



