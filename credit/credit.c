#include <cs50.h>
#include <stdio.h>

// Initialize my functions
int sum_alternative_digits(long int n);



int main(void)
{
	long int n = get_long("Numbers: ");

	int z = (n % 10) + alternative_digits(n);

	printf("%i", z);

}


int alternative_digits(long int n)
{
	long int y;
	for(y = 3; (n/10^y)>=(0.1); y = y + 2)
	{
		int j = (n % 10^(y)/10^(y - 1)) - (n % 10^(y - 1))/(10^(y - 1));
	}
	return 1;
}

