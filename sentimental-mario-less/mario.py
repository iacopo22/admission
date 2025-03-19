from cs50 import get_int

# Prompt the user for the height of the pyramid
height = get_int("Height of the half-pyramid: ")

# Prompt the user for an integer between 1 and 8
# Prompt again if it's not a valid integer
while (height > 8 or height < 1):
    height = get_int("Height of the half-pyramid: ")

x = 0
y = 0
for rows in range(height):
    for spaces in range(height - 1 - x):
        print(" ", end="")
    for blocks in range(y):
        print("#", end="")
    # the last block and then \n
    print("#")
    # Increase the number of blocks and decrease
    # the number of spaces
    x += 1
    y += 1
