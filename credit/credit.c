#include <cs50.h>
#include <stdio.h>
#include <math.h>


int alternative_digits(double x);

int main(void)
{
	// Get the number of the card from the user
	double ncard = get_long("Number of the card: ");

	//Last digit
	long int last_digit = ncard % 10;
	printf("%li\n", last_digit);

	//Sum of the


}


int alternative_digits(double x)
{
	double y;
	for(y=2; (x/10)>=0.1; y++)
	{
	double sum = ((x % pow(10, y)) / pow(10, y-1)) - ((x % pow(10, y+1)) / pow(10, y-1));
	printf("%li\n", alternative_digits);
	}
	return sum;
}