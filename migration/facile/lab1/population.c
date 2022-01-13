#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int x;
    int y;
    do
    {
        x = get_int("Start size (greater than 8): ");
    }
    while (x < 9);

    // TODO: Prompt for end size
    do
    {
        y = get_int("End size (at least as great as start size): ");
    }
    while (y < x);


    // TODO: Calculate number of years until we reach threshold

    // z=number of loops --> number of years until we reach threshold


    //loop to calculate x --> the variation of the population

    int z;

    for (z = 0; x < y; z++)

    {
        x = x - x / 4 + x / 3;
    }


    // TODO: Print number of years

    printf("Years: %i", z);
}


