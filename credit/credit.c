#include <cs50.h>
#include <stdio.h>
#include <math.h>



int main(void)
{
	// Get the number of the card from the user
	long ncard = get_long("Number of the card: ");


	int y;
	long x = ncard;
	long z;
	long c;


	for(y=0; y<=16; y++)
	{
		c = (x / pow(10, y));
		z = c % 10;
		printf("%li\n", z);
		if(y==1 || y==3 || y==5 || y==7 || y==9 || y==11 || y==13 || y==15)
		{
			long sum_secondtolast = z;
			printf("Second to last: %li\n", sum_secondtolast);
		}

	}




}







