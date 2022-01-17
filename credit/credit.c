#include <cs50.h>
#include <stdio.h>
#include <math.h>




int main(void)
{
	// Get the number of the card from the user
	long int ncard = get_long("Number of the card: ");
	long int last_digit = (ncard / 1) % 10;

	int y= 0;
	int x = ncard;
	int z;
	while(y=<16)
	{
		x = (x / pow(10, y));
		z = x % 10;
		printf("%i\n", z);
		y++;
	}





}







