from sys import argv

# Prints a command-line argument
if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")

# Printing command-line arguments, indexing into argv
for i in range(len(argv)):
    print(argv[i])

# Printing command-line arguments
for arg in argv:
    print(arg)
