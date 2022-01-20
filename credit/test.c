#include <cs50.h>
#include <stdio.h>

bool triangle(float a, float b, float c);

int main(void)
{
	float x = get_float("One of the side: ");
	float y = get_float("One of the side: ");
	float z = get_float("One of the side: ");

	bool f;

	 f = bool triangle(float x, float y, float z);

	printf("%d\n", f);

}


bool triangle(float a, float b, float c)
{
	bool n;
	if(a + b <= c || a + c <= b || c + b <= a)
	{
		return n = false;
	}

	if(a <= 0 || b <= 0 || c <= 0)
	{
		return n = false;
	}

	return n=true;
}