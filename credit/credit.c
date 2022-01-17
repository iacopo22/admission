#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Initialize my function
long int single_digits(long last);


int main(void)
{
	// Get the number of the card from the user
	long int ncard = get_long("Number of the card: ");
	printf("%li\n", ncard);



}


// Function to find single digits
long int single_digits(long last)
{
	do
	{
		last = (last / 10) % 10;
		printf("%li\n", last);
	}
	while(last >= 0.1);
	return last;
}


