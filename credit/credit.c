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
	long secondtolast, _secondtolast, __secondtolast;
	long thirdtolast;
	long fourthtolast, _fourthtolast, __fourthtolast;
	long fifthtolast;
	long sixthtolast, _sixthtolast, __sixthtolast;
	long seventhtolast;
	long eighthtolast, _eighthtolast, __eighthtolast;
	long ninthtolast;
	long tenthtolast, _tenthtolast, __tenthtolast;
	long sixth;
	long fifth, _fifth, __fifth;
	long fourth;
	long third, _third, __third;
	long second;
	long first, _first, __first;



	for(y=-1; y<=16; y++)
	{
		c = (ncard / pow(10, y));
		z = c % 10;

		switch(y)
		{
		case 0: (y = 0);
			last = z;
			printf("Last: %li\n", last);
			break;

		case 1:
			secondtolast = z;
			if((secondtolast*2) >= 10)
			{
				_secondtolast = (secondtolast*2) % 10;
				__secondtolast = ((secondtolast*2)/10)%10;
				secondtolast = 0;
				printf("_Secondtolast: %li\n", _secondtolast);
				printf("__Secondtolast: %li\n", __secondtolast);
			}
			else
			{
				_secondtolast = 0;
				__secondtolast = 0;
				printf("Secondtolast: %li\n", secondtolast);
			}
			break;

		case 2:
			thirdtolast = z;
			printf("Third to last: %li\n", thirdtolast);
			break;

		case 3:

			fourthtolast = z;
			if((fourthtolast*2) >= 10)
			{
				_fourthtolast = (fourthtolast*2) % 10;
				__fourthtolast = ((fourthtolast*2)/10) % 10;
				fourthtolast = 0;
				printf("_Fourthtolast: %li\n", _fourthtolast);
				printf("__Fourthtolast: %li\n", __fourthtolast);
			}
			else
			{
				_fourthtolast = 0;
				__fourthtolast = 0;
				printf("Fourthtolast: %li\n", fourthtolast);
			}
			break;

		case 4:

			fifthtolast = z;
			printf("Fifth to last: %li\n", fifthtolast);
			break;

		case 5:

			sixthtolast = z;
			if((sixthtolast*2) >= 10)
			{
				_sixthtolast = (sixthtolast*2) % 10;
				__sixthtolast = ((sixthtolast*2)/10)%10;
				sixthtolast = 0;
				printf("_Sixthtolast: %li\n", _sixthtolast);
				printf("__Sixthtolast: %li\n", __sixthtolast);
			}
			else
			{
				_sixthtolast = 0;
				__sixthtolast = 0;
				printf("Sixthtolast: %li\n", sixthtolast);
			}
			break;

		case 6:

			seventhtolast = z;
			printf("Seventh to last: %li\n", seventhtolast);
			break;

		case 7:

			eighthtolast = z;
			if((eighthtolast*2) >= 10)
			{
				_eighthtolast = (eighthtolast*2) % 10;
				__eighthtolast = ((eighthtolast*2)/10)%10;
				eighthtolast = 0;
				printf("_Eighthtolast: %li\n", _eighthtolast);
				printf("__Eighthtolast: %li\n", __eighthtolast);
			}
			else
			{
				_eighthtolast = 0;
				__eighthtolast = 0;
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
				tenthtolast = 0;
				printf("_Tenthtolast: %li\n", _tenthtolast);
				printf("__Tenthtolast: %li\n", __tenthtolast);
			}
			else
			{
				_tenthtolast = 0;
				__tenthtolast = 0;
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
				fifth = 0;
				printf("_Fifth: %li\n", _fifth);
				printf("__Fifth: %li\n", __fifth);
			}
			else
			{
				_fifth = 0;
				__fifth = 0;
				printf("Fifth: %li\n", fifth);
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
				_third = (third*2) % 10;
				__third = ((third*2)/10)%10;
				third = 0;
				printf("_Third: %li\n", _third);
				printf("__Third: %li\n", __third);
			}
			else
			{
				_third = 0;
				__third = 0;
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
				first = 0;
				printf("_First: %li\n", _first);
				printf("__First: %li\n", __first);
			}
			else
			{
				_first = 0;
				__first = 0;
				printf("__First: %li\n", first);
			}
			break;
		}
	}

int sum_from_the_last = last + thirdtolast + fifthtolast + seventhtolast + ninthtolast + sixth + fourth + second;
printf("Sum of alternative digits from last one: %i\n", sum_from_the_last);

int sum_from_secondtolast = first*2 + _first + __first + third + _third + __third + fifth + _fifth + __fifth + tenthtolast + _tenthtolast + __tenthtolast + eighthtolast + _eighthtolast + __eighthtolast + sixthtolast + _sixthtolast + __sixthtolast + fourthtolast + _fourthtolast + __fourthtolast + secondtolast + _secondtolast + __secondtolast;

printf("Sum of alternative digits from second one: %i\n", sum_from_secondtolast);



}







