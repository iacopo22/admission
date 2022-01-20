#include <cs50.h>
#include <stdio.h>

int triangle(int a, int b, int c);

int main(void)
{
	float x = get_int("One of the side: ");
	float y = get_int("One of the side: ");
	float z = get_int("One of the side: ");

	int triangle(int x, int y, int z);



}


int triangle(int a, int b, int c)
{
	if(a + b > c || a + c > b || c + b > a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}