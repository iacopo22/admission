#include <cs50.h>
#include <stdio.h>

void triangle(float a, float b, float c);

int main(void)
{
	float x = get_int("One of the side: ");
	float y = get_int("One of the side: ");
	float z = get_int("One of the side: ");

	 j = triangle(x, y, z);



}


void triangle(float a, float b, float c)
{
	if(a + b > c || a + c > b || c + b > a)
	{
		true;
	}
	else
	{
		false;
	}
}