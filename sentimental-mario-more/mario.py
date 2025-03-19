from cs50 import get_int

# Prompt the user for the height of the pyramid
height = get_int("Height of the pyramid: ")

# Prompt the user until a valid integer is given
while (height < 1 or height > 8):
    height = get_int("Height of the pyramid: ")

x = 0
y = 0

for rows in range(height):
    # First half-pyramid
    for spaces in range(height - 1 - x):
        print(" ", end="")
    for blocks in range(y + 1):
        print("#", end="")
    print("  ", end="")
    # Second half-pyramid
    for blocks2 in range(y):
        print("#", end="")
    # Last block and \n
    print("#")
    x += 1
    y += 1
