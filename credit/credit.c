#include <cs50.h>
#include <stdio.h>

// Initialize my functions
int alternative_digits(int digits);



int main(void)
{
	int y;
	long int n = get_long("Numbers: ");

	for(y = 2; (n/10^y)>=1; y++)
	{
		(n % 10) - ((n % 10^y - n % 10^y)/10^y);
	}

}
