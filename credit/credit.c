#include <cs50.h>
#include <stdio.h>
#include <math.h>



int main(void)
{
	// Get the number of the card from the user
	long ncard = get_long("Number of the card: ");


	int y;
	long z;
	long c;


	for(y=0; y<=16; y++)
	{
		c = (ncard / pow(10, y));
		z = c % 10;
		printf("%li\n", z);


		switch(y)
		{
		case 1: (y = 2);
			long secondtolast = z;
			printf("Second to last: %li\n", secondtolast);
			break;

		case 2: (y = 4);

			long fourthtolast = z;
			printf("Fourth to last: %li\n", fourthtolast);
			break;

		case 3: (y = 6);

			long sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 4: (y = 8);

			long eighthtolast = z;
			printf("Eightth to last: %li\n", eighthtolast);
			break;
		}




	}




}







