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

		switch(y)
		{
		case 0: (y = 0);
			long last = z;
			printf("Last: %li\n", last);
			break;

		case 1: (y = 1);
			long secondtolast = z;
			printf("Second to last: %li\n", secondtolast);
			break;

		case 2: (y = 2);
			long thirdtolast = z;
			printf("Third to last: %li\n", thirdtolast);
			break;

		case 3: (y = 3);

			long fourthtolast = z;
			printf("Fourth to last: %li\n", fourthtolast);
			break;

		case 4: (y = 4);

			long fifthtolast = z;
			printf("Fifth to last: %li\n", fifthtolast);
			break;

		case 5: (y = 5);

			long sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 6: (y = 6);

			long seventhtolast = z;
			printf("Seventh to last: %li\n", seventhtolast);
			break;

		case 7: (y = 7);

			long eighthtolast = z;
			printf("Eighth to last: %li\n", eighthtolast);
			break;

		case 8: (y = 8);

			long ninthtolast = z;
			printf("Ninth to last: %li\n", ninthtolast);
			break;

		case 9: (y = 9);

			long tenthtolast = z;
			printf("Tenth to last: %li\n", tenthtolast);
			break;

		case 10: (y = 10);

			long sixth = z;
			printf("Sixth: %li\n", sixth);
			break;

		case 11: (y = 11);

			long fifth = z;
			printf("Fifth: %li\n", fifth);
			break;

		case 12: (y = 12);

			long fourth = z;
			printf("Fourth: %li\n", fourth);
			break;

		case 13: (y = 13);

			long third = z;
			printf("Third: %li\n", third);
			break;

		case 14: (y = 14);

			long second = z;
			printf("Second: %li\n", second);
			return second;
			break;

		case 15: (y = 15);

			long first = z;
			printf("First: %li\n", first);
			break;
		}
	}






}







