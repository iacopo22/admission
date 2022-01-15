#include <cs50.h>
#include <stdio.h>

//Initialize my functions
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

    // Ask how many cents the customer is owed


    //Define my function int get_cents
    int get_cents(void)
    {
      int cents;
       do
       {
         cents = get_int("Cents owed: ");
       }
       while (cents < 0);
       return cents;
    }


    // Calculate the number of quarters to give the customer

    //Define my function int calculate_quarters
     int numberq;
    int calculate_quarters(int cents)
    {
      for(numberq=0; cents>=25; numberq++)
      {
      cents = cents - 25;
      }
      return numberq;
    }


    int main(void)
{
    //Recall my function int get_cents
    int cents;
     cents = get_cents();

    //Recall my function int calculate_quarters
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    printf("%i", numberq);



}