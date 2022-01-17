#include <cs50.h>
#include <stdio.h>
#include <math.h>




int main(void)
{
	// Get the number of the card from the user
	long int ncard = get_long("Number of the card: ");
	long int last_digit = (ncard / 1) % 10;

	int y;
	for(y=1; y<=16; y++)
	{
		ncard = (ncard / pow(10, y));
		printf("%ld\n", ncard);
	}





}







