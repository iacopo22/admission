#include <cs50.h>
#include <stdio.h>

long exponential(int n);

int main(void)
{
    int length = 0;

    // Long to avoid overflow problem
    long number = get_long("Card number: ");

    // Length of the number
    // If I divide by 15 and the number is not equal to zero then length is 16, otherwhise
    // I try with smaller numbers
    if ((number / exponential(15)) != 0)
    {
        length = 16;
    }
    else if ((number / exponential(14)) != 0)
    {
        length = 15;
    }
    else if ((number / exponential(13)) != 0)
    {
        length = 14;
    }
    else if ((number / exponential(12)) != 0)
    {
        length = 13;
    }
    // If it's less than 13 then is invalid
    else
    {
        printf("INVALID\n");
    }

    int y = 1;
    int sum = 0;
    int digit;
    long digits;
    int doubled;

    for (int j = 0; j < length; j++)
    {
        // To isolate the digit. I obtain the number from the module and then
        // I divide that number by 10 and the result is the digit (since is an int
        // the decimal will be truncated)
        digits = (number % exponential(y));
        digit = (digits / exponential(y - 1));

        // If y is even then the program multiply the digiit by two
        //  and the adds the digit to the sum
        if (y % 2 == 0)
        {
            doubled = digit * 2;
            if (doubled >= 10)
            {
                // If the digit multiplied by two is greater than 10,
                // then I have to sum the digits of the program
                sum = sum + doubled / 10 + doubled % 10;
            }
            else
            {
                sum += doubled;
            }
            // If y is odd the program adds the digit to the sum
        }
        else
        {
            sum += digit;
        }
        // Increment the power to isolate another digit on the left
        y += 1;
    }

    // Second digit MASTERCARD
    int second_digit_M = (number / exponential(14)) % 10;

    // Second digit AMEX
    int second_digit_X = (number / exponential(13)) % 10;

    // If the last digit of the sum is != 0 the number is invalid
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if (length == 15)
        {
            if (number / exponential(14) == 3 && (second_digit_X == 4 || second_digit_X == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 16)
        {
            if ((number / exponential(15)) == 5 && (second_digit_M >= 1 && second_digit_M <= 5))
            {
                printf("MASTERCARD\n");
            }
            else if (number / exponential(15) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (length == 13)
        {
            if (number / exponential(12) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}

// Function to make power of 10 based on the number in input (which is the exponent)
long exponential(int n)
{
    long x = 1;
    for (int i = 0; i < n; i++)
    {
        x = x * 10;
    }
    return x;
}
