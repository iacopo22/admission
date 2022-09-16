#include <cs50.h>
#include <stdio.h>

bool only_digits(string input);

int main(int argc, string argv[])
{
	//If there aren't input or if there are more then one, the program prints an error
	if (argv[1] == NULL || argv[2] != NULL)
	{
		printf("Usage: ./caesar key\n");
	}
	return 1;

	//The input has to be greater and equal to 0 and smaller than 10
	string f;
	bool x = only_digits(f);


	//If it's not a decimal point the program prints an error


	//If the k is greater than 26, the program should convert the letter in another letter following alphabetical order (check ASCII)


}


bool only_digits(string input)
{
	if (input <= '57' && input >= 48)
	{
		return 0;
	}
	return true;
}