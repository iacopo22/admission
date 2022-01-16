#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Program receive numbers of the card from the user
	long int n = get_long("Numbers: ");


	// Verify the checksum of Luhn's algorithm
	int y = (n % 10);
	printf("%i", y);


}