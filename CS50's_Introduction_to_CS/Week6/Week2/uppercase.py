# from cs50 import get_string

s = input("Before: ")
print("After:  ", end="")
for c in s:
    # Iterating over each char at a time.
    print(c.upper(), end="")
print()
# Using upper function:
print(f"After:  {s.upper()}")
