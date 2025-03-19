from cs50 import get_int
from cs50 import get_string


def sum_digits(n):
    if n >= 10:
        # Last digit
        d = n % 10
        # First digit
        d_ = n // 10
        n = d + d_
        return n
    else:
        return n


# Prompt the user for the card's number
number = get_string("Card's number: ")
length = len(number)


if length != 13 and length != 15 and length != 16:
    print("INVALID")

# Cast the number as an int
number = int(number)
exp = 0
sum = 0
index = 1

for _ in range(length):
    # From second to last
    if index % 2 == 0:
        # The program divides the number by 10^exp, where
        # exp gets bigger in every iteration
        digit = (int(number / 10**exp) % 10) * 2
        sum = sum_digits(digit) + sum
    # From the last digit
    else:
        sum = (int(number / 10**exp) % 10) + sum

    exp += 1
    index += 1


last_digit = sum % 10

first_digit = 0
second_digit = 0

if length == 13:
    first_digit = number // 10 ** 12
elif length == 14:
    first_digit = number // 10 ** 13
elif length == 15:
    first_digit = number // 10 ** 14
    second_digit = (number // 10 ** 13) % 10
elif length == 16:
    first_digit = number // 10 ** 15
    second_digit = (number // 10 ** 14) % 10


if last_digit != 0:
    print("INVALID")
else:
    if (length == 13 or length == 16) and first_digit == 4:
        print("VISA")
    elif length == 16 and first_digit == 5 and (second_digit >= 1 and second_digit <= 5):
        print("MASTERCARD")
    elif length == 15 and first_digit == 3 and (second_digit == 4 or second_digit == 7):
        print("AMEX")
    else:
        print("INVALID")
