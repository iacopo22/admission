#include <cs50.h>
#include <stdio.h>

int main(void)

{
    int x;
    //User prompts a number from 1 to 8 for the height of the pyramid
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8);


    int y;
    int c = x;
    int z;
    int b = 0;
    int j;
    int l;
    int m = 2;
    int a;
    int d = 0;

    //The program creates the blocks according to the user's input height


    //The first loop creates the rows
    for (y = 0; y < x; y++)
    {

        //The second loops creates the spaces

        c--;
        for (z = 0; z < c; z++)
        {
            printf(" ");
        }

        //The third loop creates the hashes
        b++;
        for (j = 0; j < b; j++)
        {
            printf("#");
        }
        //The fourth loop creates the spaces between the two semi-pyramids
        for (l = 0; l < m; l++)
        {
            printf("  ");
        }
        //The fifth loop creates the hashes

        d++;
        for (a = 0; a < b; a++)
        {
            printf("#");
        }


        printf("\n");
    }


}