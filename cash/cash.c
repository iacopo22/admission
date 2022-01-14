#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;
    // Ask how many cents the customer is owed
    do
    {
     cents = get_int("Cents: ");
    }
    while (cents < 0);

    // Calculate the number of quarters to give the customer
    int quarters = 25;
    int numberq;

    for(numberq=0; cents>=25; numberq++)
    {
     cents = cents - quarters;
    }
    printf("Number of quarters as change: %i", numberq);






}
