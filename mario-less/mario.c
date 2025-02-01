#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt for the height of the pyramid
    int height;
    do
    {
        height = get_int("Height of the pyramid: ");
    }
    while (height < 1);

    int x = 1;
    int y = height - 1;

    // Loop for the rows
    for (int row = 0; row < height; row++)
    {
        // Create space before printing #
        for (int i = 0; i < y; i++)
        {
            printf(" ");
        }
        for (int j = 0; j < x; j++)
        {
            printf("#");
        }
        // In each following row there is a decreasing number of " " and increasing number of #
        x++;
        y--;

        printf("\n");
    }


}