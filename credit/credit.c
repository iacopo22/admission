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

		switch(y)
		{
		case 1: (y = 1);
			long secondtolast = z;
			printf("Second to last: %li\n", secondtolast);

		case 2: (y = 3);

			long thirdtolast = z;
			printf("Third to last: %li\n", thirdtolast);

		case 3: (y = 5);

			long fourthtolast = z;
			printf("Fourth to last: %li\n", fourthtolast);

		case 4: (y = 7);

			long fifthtolast = z;
			printf("Fifth to last: %li\n", fifthtolast);
		}

	}




}







