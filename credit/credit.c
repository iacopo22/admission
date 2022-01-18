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
		break;

	case 1:
		secondtolast = z;
		if((secondtolast*2) >= 10)
		{
			_secondtolast = (secondtolast*2) % 10;
			__secondtolast = ((secondtolast*2)/10)%10;
			secondtolast = 0;
		}
		else
		{
			_secondtolast = 0;
			__secondtolast = 0;
		}
		break;

	case 2:
		thirdtolast = z;
			break;

	case 3:

		fourthtolast = z;
		if((fourthtolast*2) >= 10)
		{
			_fourthtolast = (fourthtolast*2) % 10;
			__fourthtolast = ((fourthtolast*2)/10) % 10;
			fourthtolast = 0;
		}
		else
		{
			_fourthtolast = 0;
			__fourthtolast = 0;
		}
		break;

	case 4:

		fifthtolast = z;
		break;

	case 5:

		sixthtolast = z;
		if((sixthtolast*2) >= 10)
		{
			_sixthtolast = (sixthtolast*2) % 10;
			__sixthtolast = ((sixthtolast*2)/10)%10;
			sixthtolast = 0;
		}
		else
		{
			_sixthtolast = 0;
			__sixthtolast = 0;
		}
		break;

	case 6:

		seventhtolast = z;
		break;

	case 7:

		eighthtolast = z;
		if((eighthtolast*2) >= 10)
		{
			_eighthtolast = (eighthtolast*2) % 10;
			__eighthtolast = ((eighthtolast*2)/10)%10;
			eighthtolast = 0;
		}
		else
		{
			_eighthtolast = 0;
			__eighthtolast = 0;
		}
		break;

    case 8:

		ninthtolast = z;
		break;

	case 9:

		tenthtolast = z;
		if((tenthtolast*2)>=10)
		{
			_tenthtolast = (tenthtolast*2) % 10;
			__tenthtolast= ((tenthtolast*2)/10)%10;
			tenthtolast = 0;
		}
		else
		{
			_tenthtolast = 0;
			__tenthtolast = 0;
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
		}
		else
		{
			_third = 0;
			__third = 0;
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
		}
		else
		{
       _first = 0;
       __first = 0;
     }
             break;
        }
    }

    int sum_from_the_last = last + thirdtolast + fifthtolast + seventhtolast + ninthtolast + sixth + fourth + second;
    printf("Sum of alternative digits from last one: %i\n", sum_from_the_last);

    int sum_from_secondtolast = first * 2 + _first + __first + third * 2 + _third + __third + fifth * 2 + _fifth + __fifth + tenthtolast * 2
	                           + _tenthtolast + __tenthtolast + eighthtolast * 2 + _eighthtolast + __eighthtolast + sixthtolast * 2 + _sixthtolast
                               + __sixthtolast + fourthtolast * 2 + _fourthtolast + __fourthtolast + secondtolast * 2 + _secondtolast + __secondtolast;

    printf("Sum of alternative digits from second one: %i\n", sum_from_secondtolast);

    int sum = sum_from_secondtolast + sum_from_the_last;
    printf("Sum: %i\n", sum);

    int last_sum = sum % 10;
    printf("Is a zero? %i\n", last_sum);



    if( pow(10, 14) <= ncard <= 5 * (pow(10, 14)) && (last_sum == 0) && (second == 3) && ((_third == 4 && __third == 1) || third == 4))
    {
        printf("AMEX\n");
    }
    else if( pow(10, 15) <= ncard <= 6 * (pow(10, 15)) && (last_sum == 0) && (second == 1 || second == 2 || second == 3 || second == 4
               || second == 5) && (_first == 0 && __first == 1))
    {
        printf("MASTERCARD\n");
    }
   else if( pow(10, 12) <= ncard <= 5 * (pow(10, 15)) && (last_sum == 0) && (first == 4 || second == 4 || third == 4 || fourth == 4))
   {
       printf("VISA\n");
   }
     else
     {
        printf("INVALID\n");
     }





}







