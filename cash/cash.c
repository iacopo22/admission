#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int change;
    do
    {
        // Prompt user for the change owed
        change = get_int("Change: ");
    }
    while (change < 0);

    // Declare a variable to store the number of coins
    int counter = 0;
    do
    {
        // If the change is greater than 25, the program subtracts 25 and add one to the counter
        if (change >= 25)
        {
            change -= 25;
            counter++;
        }
        else if (10 <= change && change < 25)
        {
            change -= 10;
            counter++;
        }
        else if (5 <= change && change < 10)
        {
            change -= 5;
            counter++;
        }
        else if (change < 5 && change > 0)
        {
            change -= 1;
            counter++;
        }
    }
    // Repeat the process
    while (change > 0);

    // Print the number of coins
    printf("%i\n", counter);
}