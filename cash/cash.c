#include <cs50.h>
#include <stdio.h>


int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int get_cents(void);
    {
    do
    {
      cents = get_cents(int);
    }
    while (cents < 0);
    return cents;
    }


}