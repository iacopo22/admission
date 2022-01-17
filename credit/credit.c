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

		if(y==1)
		{
			long secondtolast = z;
			printf("Second to last: %li\n", secondtolast);
		}
		else(y=3);
		{
			long thirdtolast = z;
			printf("Third to last: %li\n", thirdtolast);
		}
		else(y==5);
		{
			long fourthtolast = z;
			printf("Fourth to last: %li\n", fourthtolast);
		}
		else(y==7);
		{
			long fifthtolast = z;
			printf("Fourth to last: %li\n", fifthtolast);
		}

	}




}







