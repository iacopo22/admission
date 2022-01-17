#include <cs50.h>
#include <stdio.h>
#include <math.h>




int main(void)
{
	// Get the number of the card from the user
	long int ncard = get_long("Number of the card: ");
	long int last_digit = (ncard / 1) % 10;

	long int x;
	while(ncard>=10)
	{
		x = ncard / 10;
		printf("%li\n", ncard);
	}

	long int digits = ncard % 10;
	printf("Digits: %li", digits);




}







