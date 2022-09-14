#include <cs50.h>
#include <stdio.h>

bool valid_triangle(int x, int y, int z);

int main(void)
{
	int l1 = get_int("Length of one side: ");
	int l2 = get_int("Length of one side: ");
	int l3 = get_int("Length of one side: ");

	bool valid_triangle(int l1, int l2, int l3);
}

bool valid_triangle(int l1, int l2, int l3)
{

	if ((l1+l2>l3 || l2+l3>l1 || l1+l3>l2) && (l1>0 && l2>0 && l3>0))
	{
		return true;
		printf("It's a triangle");
    }
	else
	{
		return false;
		printf("It's not a triangle");
	}

}