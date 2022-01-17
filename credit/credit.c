#include <cs50.h>
#include <stdio.h>
#include <math.h>




int main(void)
{
	// Get the number of the card from the user
	long int ncard = get_long("Number of the card: ");
	long int last_digit = (ncard / 1) % 10;


	do
	{
		ncard = (last_digit / 10) % 10;
		printf("%li\n", ncard);
	}
	while(ncard >= 0.1);




}







