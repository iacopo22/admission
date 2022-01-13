#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int x;
    // Ask how many cents the customer is owed
    do
    {
     x = get_int("Cents: ");
    }
    while (x < 0);

    // Calculate the number of quarters to give the customer

    int quarters = calculate_quarters();

    cents = cents - quarters * 25;



}
