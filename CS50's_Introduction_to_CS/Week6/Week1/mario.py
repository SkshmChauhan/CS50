# Printing a column of 3 bricks
for i in range(3):
    print("#")

# Printing a row of 4 question marks
for i in range(4):
    print("?", end="")
print()

# Printing a row of 4 question marks without a loop
print("?" * 4)

# Printing a 3-by-3 grid of bricks with loops
for i in range(3):
    for j in range(3):
        print("#", end="")
    print()

