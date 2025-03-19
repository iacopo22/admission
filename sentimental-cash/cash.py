from cs50 import get_float

# Prompt the user for the change owed
change = get_float("Change: ")

# If the float is not valid, continue to promt the user
while change < 0:
    change = get_float("Change: ")

# I convert dollars to cents (rounding to avoid the imprecision
# of the floating value)
change = int(round(change * 100, 1))
# Initialize the number of coins to zero
coins = 0

# Repeat the process until change is equal to 0
while change > 0:
    if change >= 25:
        # I add to the number of coins the ratio
        # between the change owed and the coin
        coins = coins + (change // 25)
        change = change - (change // 25) * 25
    elif change >= 10:
        coins = coins + (change // 10)
        change = change - (change // 10) * 10
    elif change >= 5:
        coins = coins + (change // 5)
        change = change - (change // 5) * 5
    else:
        coins = coins + (change // 1)
        change = change - (change // 1) * 1

# Print the number of coins
print(f"{coins}")
