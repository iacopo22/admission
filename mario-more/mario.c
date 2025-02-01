#include <stdio.h>
#include <cs50.h>

// Declare functions
void print_space(int x);
void print_block1(int x);


int main(void)
{
    int height;
    // Get the height of the pyramid from the user
    do
    {
        height = get_int("Height of the pyramid: ");
    }
    while (height < 1 || height > 8);

    int space = height - 1;

    int count = 1;
    int count2 = 1;
    for (int row = 0; row < height; row++)
    {
        print_space(space);
        // For every row there is one less space
        space--;

        print_block1(count);

        // Gap between adjacent pyramids
        printf("  ");

        print_block1(count);

        // For every row there is one more block
        count++;

        printf("\n");
    }

}


void print_space(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf(" ");
    }
}


void print_block1(int x)
{
    for (int i = 0; i < x; i++)
    {
        printf("#");
    }
}