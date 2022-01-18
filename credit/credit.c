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
	long _first, __first;
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
			if((eighthtolast*2) >= 10)
			{
				_eighthtolast = (tenthtolast*2) % 10;
				__eighthtolast = ((tenthtolast*2)/10)%10;
				printf("_Eighthtolast: %li\n", _eighthtolast);
				printf("-Eighthtolast: %li\n", __eighthtolast);
			}
			else
			{
				printf("Eighthtolast: %li\n", eighthtolast);
			}
			printf("Fourth to last: %li\n", fourthtolast);
			break;

		case 4:

			fifthtolast = z;
			printf("Fifth to last: %li\n", fifthtolast);
			break;

		case 5:

			sixthtolast = z;
			if((eighthtolast*2) >= 10)
			{
				_eighthtolast = (tenthtolast*2) % 10;
				__eighthtolast = ((tenthtolast*2)/10)%10;
				printf("_Eighthtolast: %li\n", _eighthtolast);
				printf("-Eighthtolast: %li\n", __eighthtolast);
			}
			else
			{
				printf("Eighthtolast: %li\n", eighthtolast);
			}

			printf("Sixth to last: %li\n", sixthtolast);
			break;

		case 6:

			seventhtolast = z;
			printf("Seventh to last: %li\n", seventhtolast);
			break;

		case 7:

			eighthtolast = z;
			if((eighthtolast*2) >= 10)
			{
				_eighthtolast = (tenthtolast*2) % 10;
				__eighthtolast = ((tenthtolast*2)/10)%10;
				printf("_Eighthtolast: %li\n", _eighthtolast);
				printf("-Eighthtolast: %li\n", __eighthtolast);
			}
			else
			{
				printf("Eighthtolast: %li\n", eighthtolast);
			}
			break;

		case 8:

			ninthtolast = z;
			printf("Ninth to last: %li\n", ninthtolast);
			break;

		case 9:

			tenthtolast = z;
			if((tenthtolast*2)>=10)
			{
				_tenthtolast = (tenthtolast*2) % 10;
				__tenthtolast= ((tenthtolast*2)/10)%10;
				printf("_Tenthtolast: %li\n", _tenthtolast);
				printf("-Tenthtolast: %li\n", __tenthtolast);
			}
			else
			{
				printf("Tenthtolast: %li\n", tenthtolast);
			}
			break;


		case 10:

			 sixth = z;
			printf("Sixth: %li\n", sixth);
			break;

		case 11:

			fifth = z;
			if((fifth*2) >= 10)
			{
				_fifth = (fifth*2) % 10;
				__fifth = ((fifth*2)/10)%10;
				printf("_Fifth: %li\n", _fifth);
				printf("-Fifth: %li\n", __fifth);
			}
			else
			{
				printf("First: %li\n", fifth);
			}
			break;

		case 12:

			fourth = z;
			printf("Fourth: %li\n", fourth);
			break;

		case 13:

			third = z;
			if((third*2) >= 10)
			{
				_third = (first*2) % 10;
				__third = ((first*2)/10)%10;
				printf("_Third: %li\n", _third);
				printf("-Third: %li\n", __third);
			}
			else
			{
				printf("Third: %li\n", third);
			}
			break;

		case 14:

			second = z;
			printf("Second: %li\n", second);
			break;

		case 15:

			first = z;
			if((first*2) >= 10)
			{
				_first = (first*2) % 10;
				__first = ((first*2)/10)%10;
				printf("_First: %li\n", _first);
				printf("-First: %li\n", __first);
			}
			else
			{
				printf("First: %li\n", first);
			}
			break;
		}
	}

int sum_from_the_last = last + thirdtolast + fifthtolast + seventhtolast + ninthtolast + sixth + fourth + second;
printf("Sum of alternative digits from last one: %i\n", sum_from_the_last);

int sum_from_secondtolast = (secondtolast/1)*2 + fourthtolast*2 + sixthtolast*2 + eighthtolast*2 + tenthtolast*2 + fifth*2 + third*2 + first*2;
printf("Sum of alternative digits from second one: %i\n", sum_from_secondtolast);



}







