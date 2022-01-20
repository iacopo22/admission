#include <cs50.h>
#include <stdio.h>

void triangle(float a, float b, float c);

int main(void)
{
	float x = get_float("One of the side: ");
	float y = get_float("One of the side: ");
	float z = get_float("One of the side: ");

	bool triangle(float x, float y, float z);



}


bool triangle(float a, float b, float c)
{
	if(a + b > c || a + c > b || c + b > a)
	{
		return true;
	}
	else
	{
		return false;
	}
}