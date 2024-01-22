from cs50 import get_int

# Getting input from the user and checking it is valid
while True:
    input = get_int("Height is: ")
    if input <= 0 or input > 8:
        print("Height must be between 0 and 8.")
        continue
    else:
        break

# Printing pyramid

# Print the height of pyramid
for i in range(input):

    # Printing spaces
    for s in range(input - 1 - i):
        print(' ', end="")

    # Printing hashes
    for j in range(i + 1):
        print("#", end="")

    # Printing double space between pyramids
    print("  ", end="")

    # Printing second pyramid
    for h in range(i + 1):
        print("#", end="")

    print()
