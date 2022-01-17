#include <cs50.h>
#include <stdio.h>
#include <math.h>




int main(void)
{
	// Get the number of the card from the user
	long int ncard = get_long("Number of the card: ");
	long int last_digit = (ncard / 1) % 10;

    long int secondlat_digit;
	do
	{
		last_digit = (ncard / 10) % 10;
		secondlat_digit = (last_digit / 10) % 10;
		printf("%ld\n", secondlat_digit);
	}
	while(secondlat_digit > 10);




}







