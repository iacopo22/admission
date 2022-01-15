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
     int quarters;
    int calculate_quarters(int cents)
    {
      for(quarters=0; cents>=25; quarters++)
      {
      cents = cents - 25;
      }
      return quarters;
    }


    // Calculate the number of dimes to give the customer

    //Define my function int calculate_dimes
    int dimes;
    int calculate_dimes(int cents)
    {
      for(dimes=0; cents>=10; dimes++)
      {
        cents = cents - 10;
      }
      return dimes;
    }


    // Calculate the number of nickels to give the customer

    //Define my function int calculate_ nickels
    int nickels;
    int calculate_nickels(int cents)
    {
      for(nickels=0; cents>=5; nickels++)
      {
        cents = cents - 5;
      }
      return nickels;
    }

    // Calculate the number of pennies to give the customer
    int pennies;
    int calculate_pennies(int cents)
    {
      for(pennies=0; cents>=1; pennies++)
      {
        cents = cents - 1;
      }
      return pennies;
    }


    int main(void)
{
    //Recall my function int get_cents
    int cents;
     cents = get_cents();

    //Recall my function int calculate_quarters
     quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;
    printf("%i\n", quarters);

    //Recall my function int calculate_dimes
    dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;
    printf("%i\n", dimes);

    //Recall my function int calculate_nickels
    nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    printf("%i\n", nickels);

    //Recall my function int calculate_pennies
    pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;
    printf("%i\n", pennies);



}