#include <cs50.h>
#include <stdio.h>

//Initialize my functions
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

    // Ask how many cents the customer is owed
    int cents;

    //Define my function int get_cents
    int get_cents(void)
    {
       do
       {
         cents = get_int("Cents owed: ");
       }
       while (cents < 0);
       return cents;
    }


    // Calculate the number of quarters to give the customer

    //Define my function int calculate_quarters
    int calculate_quarters(numberq)
    {
      for(numberq=0; cents>=25; numberq++)
      return quarters;
    }


    int main(void)
{
    //Recall my function int get_cents
     cents = get_cents();

    //Recall my function int calculate_quarters
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    printf("%i", numberq);



}