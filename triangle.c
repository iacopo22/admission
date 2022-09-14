#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int x, int y, int z);

int main(void)
{
	bool valid_triangle;
}

bool valid_triangle(int l1, int l2, int l3)
{

	if (l1+l2>l3, l2+l3>l1, l1+l3>l2 && l1>0, l2>0, l3>0)
	{
		return 0;
    }
	else
	{
		return 1;
	}

}