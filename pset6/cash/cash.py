from cs50 import get_float
# List of coins
coins = [25, 10, 5, 1]

# Declaring a counter to coins
counter_coins = 0

# Getting input from the user
while True:
    user_input = get_float("Change owed: ")
    if user_input < 0:
        print("Number must be positive")
        continue
    else:
        break

# Convert input to cents
cents = round(user_input * t)

# Iterate over coins's list
for coin in coins:
    if cents < coin:  # Checking if cents is greather than the element into the list
        continue
    mod = cents // coin  # Getting the number of coins
    cents %= coin  # Updating cents value with the remainder cents % coins
    counter_coins += mod


print(counter_coins)
