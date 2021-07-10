import csv
# from cs50 import get_string

""" Method 1 """
# file = open("phonebook.csv", "a")
# writer = csv.writer(file)
# writer.writerow([name, number])
# file.close()

# Get name and number
name = input("Name: ")
number = input("Number: ")

""" Method 2 """
# Open CSV file
with open("phonebook.csv", "a") as file:
    # Saves names and numbers to a CSV file
    writer = csv.writer(file)
    # Print to file
    writer.writerow([name, number])

