#include <stdio.h>
#include <cs50.h>

long exponential(int n);

int main(void)
{
    int length = 0;

    long number = get_long("Card number: ");
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
    else
    {
        printf("INVALID\n");
    }

    int y = 1;
    int sum = 0;
    long digit;
    long digits;
    int doubled;

    for (int j = 0; j < length; j++)
    {
        digits = (number % exponential(y));
        digit = (digits / exponential(y - 1));

        //Se y è dispari sommo la cifra, se y è pari allora moltiflico per due la cifra prima di sommarla
        if (y % 2 == 0)
        {
            doubled = digit * 2;
            if (doubled >= 10)
            {
                sum = sum + doubled / 10 + doubled % 10;
            }
            else
            {
                sum += doubled;
            }
        }
        else
        {
            sum += digit;
        }
        y += 1;

    }

    // Second digit MASTERCARD
    int second_digit_M = (number / exponential(14)) % 10;

    // Second digit AMEX
    int second_digit_X = (number / exponential(13)) % 10;

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


long exponential(int n)
{
    long x = 1;
    for (int i = 0; i < n; i++)
    {
        x = x * 10;
    }
    return x;
}