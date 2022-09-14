#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;

    //Get an integer between 1 and 8 (included) for the height
    do
    {
        x = get_int("Height: ");
    }
    while (x > 8 || x < 1);


    int c = 0;
    int y;
    int j;
    int z = 0;
    int b;


    //The program creates the blocks according to the user's input height

    //First loop creates the rows

    for (y = 0; y < x; y++)
    {
        //Second and third loop creates the columns through " " and "#"
        c--;
        for (j = -x; j < c; j++)
        {
            printf(" ");
        }

        z++;
        for (b = 0; b < z; b++)
        {
            printf("#");
        }

        printf("\n");
    }

}


