#include <cs50.h>
#include <stdio.h>
#include <math.h>




int main(void)
{
	// Get the number of the card from the user
	long int ncard = get_long("Number of the card: ");


	do
	{
		ncard = (ncard / 10) % 10;
		printf("%li\n", ncard);
	}
	while(ncard >= 1);




}







