#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
	// Get the number of the card from the user
	long int ncard = get_long("Number of the card: ");

	//Last digit
	long int last_digit = ncard % 10;
	printf("%li\n", last_digit);

	//Second to last digit
	for(y)
	long int secondlast_digit = (ncard % 100 - last_digit)/10;
	printf("%li\n", secondlast_digit);


}


