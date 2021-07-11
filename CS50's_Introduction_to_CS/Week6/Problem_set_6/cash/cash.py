from cs50 import get_float

while True:
    # Getting value from user:
    value = get_float("Change owed: ")
    if value > 0:
        break

value = round(value * 100)
coins = 0
while value > 0:
    if value >= 25:
        value -= 25
    elif value >= 10:
        value -= 10
    elif value >= 5:
        value -= 5
    else:
        value -= 1
    coins += 1
print(coins)