# from cs50 import get_string

# Prompt user to agree
# s = get_string("Do you agree? ")
s = input("Do you agree? ")

# Check whether agreed
# if s == "Y" or s == "y":
if s.lower() in ["y", "yes"]:
    print("Agreed.")
# elif s == "N" or s == "n":
elif s.lower() in ["n", "no"]:
    print("Not agreed.")

