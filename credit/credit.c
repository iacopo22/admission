#include <cs50.h>
#include <stdio.h>
#include <math.h>


int alternative_digits(double n);

int main(void)
{
	// Get the number of the card from the user
	double ncard = get_long("Number of the card: ");

	//Last digit
	long int last_digit = ncard % pow(10,1);
	printf("%li\n", last_digit);


}


int alternative_digits(double ncard)
{
	double y;
	for(y=2; (ncard/10)>=0.1; y++)
	{
	double sum = ((ncard % pow(10, y)) / pow(10, y-1)) - ((ncard % pow(10, y+1)) / pow(10, y-1));
	}
	printf("%li\n", alternative_digits);

}