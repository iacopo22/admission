from cs50 import get_int

height = get_int("Height of the half-pyramid: ");

while (height > 8 or height < 1):
    height = get_int("Height of the half-pyramid: ");

x = 0
y = 0
for _ in range(height):
    for __ in range(height - 1 - x):
        print(" ", end="")
    for ___ in range(y):
        print("#", end="")
    # the last block and then \n
    print("#")
    # Increase the number of blocks and decrease
    # the number of spaces
    x += 1
    y += 1





