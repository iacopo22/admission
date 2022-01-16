#include <cs50.h>
#include <stdio.h>

// Initialize my functions
int alternative_digits(long int n);



int main(void)
{
	long int n = get_long("Numbers: ");

	int z = (n % 10) + alternative_digits(n);

}


int alternative_digits(long int n)
{
	int y;
	for(y = 2; (n/10^y)>=1; y++)
	{
		((n % 10^(y) - n % 10^(y))/10^(y));
	}
}

