from cs50 import get_int

while True:
    # Getting input from user:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break
# Iterating for rows:
for i in range(1, height + 1):
    print(" " * int(height - i), end="")
    print("#" * i, end="  ")
    print("#" * i)

