#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//I declare the function
int count_letters(string text);

int main(void)
{
	//I want the user to prompt a string, not numbers or symbols
	string text = get_string("Text: ");

	//Here the program prints the text
	printf("Text: %s\n", text);

	//I recall the function count_letters
    int length = count_letters(text);
	printf("Length: %i\n", length);


}

//I define the function
int count_letters(string text)
{
	int length = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
		//If the char is equal to 32 (=space) doesn't add one on the length because it's not a letter
		if (text[i] == 32)
		{
			return 1;
		}
        else
		{
			length ++;
		}
    }
	return length;

}
