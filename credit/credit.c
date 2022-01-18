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
	long last;
	long first;
	long secondtolast;
	long thirdtolast;
	long fourthtolast;
	long fifthtolast;
	long sixthtolast;
	long seventhtolast;
	long eighthtolast;
	long ninthtolast;
	long tenthtolast;
	long sixth;
	long fifth;
	long fourth;
	long third;
	long second;
	long first;


	for(y=0; y<=16; y++)
	{
		c = (ncard / pow(10, y));
		z = c % 10;

		switch(y)
		{
		case 0: (y = 0);
			last = z;
			printf("Last: %li\n", last);
			break;

		case 1: (y = 1);
			secondtolast = z;
			printf("Second to last: %li\n", secondtolast);
			break;

		case 2: (y = 2);
			thirdtolast = z;
			printf("Third to last: %li\n", thirdtolast);
			break;

		case 3: (y = 3);

			fourthtolast = z;
			printf("Fourth to last: %li\n", fourthtolast);
			break;

		case 4: (y = 4);

			fifthtolast = z;
			printf("Fifth to last: %li\n", fifthtolast);
			break;

		case 5: (y = 5);

			sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 6: (y = 6);

			seventhtolast = z;
			printf("Seventh to last: %li\n", seventhtolast);
			break;

		case 7: (y = 7);

			eighthtolast = z;
			printf("Eighth to last: %li\n", eighthtolast);
			break;

		case 8: (y = 8);

			ninthtolast = z;
			printf("Ninth to last: %li\n", ninthtolast);
			break;

		case 9: (y = 9);

			tenthtolast = z;
			printf("Tenth to last: %li\n", tenthtolast);
			break;

		case 10: (y = 10);

			 sixth = z;
			printf("Sixth: %li\n", sixth);
			break;

		case 11: (y = 11);

			fifth = z;
			printf("Fifth: %li\n", fifth);
			break;

		case 12: (y = 12);

			fourth = z;
			printf("Fourth: %li\n", fourth);
			break;

		case 13: (y = 13);

			third = z;
			printf("Third: %li\n", third);
			break;

		case 14: (y = 14);

			second = z;
			printf("Second: %li\n", second);
			break;

		case 15: (y = 15);

			first = z;
			printf("First: %li\n", first);
			break;
		}
	}

int sum = last + thirdtolast + fifthtolast + seventhtolast + ninthtolast + sixth + fourth + second;
printf("%li", sum);




}







