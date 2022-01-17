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
		case 1: (y = 0);
			long last = z;
			printf("Last: %li\n", last);
			break;

		case 2: (y = 1);
			long secondtolast = z;
			printf("Second to last: %li\n", secondtolast);
			break;

		case 3: (y = 2);
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

		case 5: (y = 6);

			long seventhtolast = z;
			printf("Seventh to last: %li\n", seventhtolast);
			break;

		case 5: (y = 7);

			long eighthtolast = z;
			printf("Eighth to last: %li\n", eighthtolast);
			break;

		case 5: (y = 8);

			long ninthtolast = z;
			printf("Ninth to last: %li\n", ninthtolast);
			break;

		case 5: (y = 9);

			long tenthtolast = z;
			printf("Tenth to last: %li\n", tenthtolast);
			break;

		case 5: (y = 10);

			long eleventhtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 5: (y = 11);

			long sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 5: (y = 12);

			long sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 5: (y = 13);

			long sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 5: (y = 14);

			long sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 5: (y = 15);

			long sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 5: (y = 16);

			long sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;



		}




	}




}







