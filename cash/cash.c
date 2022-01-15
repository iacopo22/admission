#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

    // Ask how many cents the customer is owed
    int cents;
int get_cents(void)
{
    do
    {
       cents = get_int("Cents owed: ");
    }
    while (cents < 0);
    return 0;
}


int main(void)
{
     cents = get_cents();
}