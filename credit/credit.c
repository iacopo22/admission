#include <cs50.h>
#include <stdio.h>
#include <math.h>


int alternative_digits(long int n);

int main(void)
{
	// Get the number of the card from the user
	long int ncard = get_long("Number of the card: ");

	//Last digit
	long int last_digit = ncard % 10;
	printf("%li\n", last_digit);

	long int secondlast_digit = ((ncard % 100) / 10) - ((ncard % 10) / 10);
	printf("%li\n", secondlast_digit);



}


int alternative_digits(long int n)
{
	long int y;
	for(y=2; (n/10)>=0.1; y++)
	{
	long int sum = ((ncard % pow(10, y)) / pow(10, y-1)) - ((ncard % pow(10, y+1)) / pow(10, y-1));
	}
	printf("%li\n", alternative_digits);

}