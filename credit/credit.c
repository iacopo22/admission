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



	for(y=0; y<=16; y++)
	{
		c = (ncard / pow(10, y));
		z = c % 10;

		switch(y)
		{
		case 0:
			last = z;
			printf("Last: %li\n", last);
			break;

		case 1:
			secondtolast = z;
			printf("Second to last: %li\n", secondtolast);
			break;

		case 2:
			thirdtolast = z;
			printf("Third to last: %li\n", thirdtolast);
			break;

		case 3:

			fourthtolast = z;
			printf("Fourth to last: %li\n", fourthtolast);
			break;

		case 4:

			fifthtolast = z;
			printf("Fifth to last: %li\n", fifthtolast);
			break;

		case 5:

			sixthtolast = z;
			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 6:

			seventhtolast = z;
			printf("Seventh to last: %li\n", seventhtolast);
			break;

		case 7:

			eighthtolast = z;
			printf("Eighth to last: %li\n", eighthtolast);
			break;

		case 8:

			ninthtolast = z;
			printf("Ninth to last: %li\n", ninthtolast);
			break;

		case 9:

			tenthtolast = z;
			printf("Tenth to last: %li\n", tenthtolast);
			break;

		case 10:

			 sixth = z;
			printf("Sixth: %li\n", sixth);
			break;

		case 11:

			fifth = z;
			printf("Fifth: %li\n", fifth);
			break;

		case 12:

			fourth = z;
			printf("Fourth: %li\n", fourth);
			break;

		case 13:

			third = z;
			printf("Third: %li\n", third);
			break;

		case 14:

			second = z;
			printf("Second: %li\n", second);
			break;

		case 15:

			first = z;
			printf("First: %li\n", first);
			break;
		}
	}

int sum_from_the_last = last + thirdtolast + fifthtolast + seventhtolast + ninthtolast + sixth + fourth + second;
printf("Sum of alternative digits from last one: %i\n", sum_from_the_last);

int sum_from_secondtolast = (secondtolast/1)*2 + fourthtolast*2 + sixthtolast*2 + eighthtolast*2 + tenthtolast*2 + fifth*2 + third*2 + first*2;
printf("Sum of alternative digits from second one: %i\n", sum_from_secondtolast);



}







