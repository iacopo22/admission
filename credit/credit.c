#include <cs50.h>
#include <stdio.h>

// Initialize my functions
int alternative_digits(float n);



int main(void)
{
	float n = get_long("Numbers: ");

	float z = (n % 10) + alternative_digits(n);

	printf("%f", z);

}


int alternative_digits(float n)
{
	float y;
	for(y = 3; (n/10^y)>=0.1; y = y + 2)
	{
		float j = (n % 10^(y)/10^(y - 1)) - (n % 10^(y - 1))/(10^(y - 1));
	}
	return n;
}

