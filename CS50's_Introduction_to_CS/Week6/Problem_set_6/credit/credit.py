from cs50 import get_int

while True:
    # Getting value from user:
    number = get_int("Number: ")
    if int(number) > 0:
        break

# Declaring variables
number = str(number)
normal = number[::-1]

# Storing number in an array:
arr = [num for num in str(number)]
arr2 = []
for i in range(1, len(normal), 2):
    arr2.append(normal[i])
    arr.remove(normal[i])

# Validating length of the number
if len(number) < 13:
    print("INVALID")
else:
    temp = []
    # Multiplying digits starting from second-last by 2:
    for i in range(0, len(arr2)):
        newval = int(arr2[i]) * 2
        newval = str(newval)
        if len(newval) < 2:
            temp.append(newval)
        else:
            for digit in newval:
                temp.append(digit)
    arr2 = temp
    total = 0
    # Summation of the digit of products:
    for i in arr:
        total += int(i)
    # Summation of rest of the digits of the number:
    for j in arr2:
        total += int(j)
    # Checking whether the number is valid or not:
    if str(total)[-1] == "0":
        startNum = int(number[0:2])
        if (startNum == 34 or startNum == 37) and len(number) == 15:
            print("AMEX")
        elif 51 <= startNum <= 55 and len(number) == 16:
            print("MASTERCARD")
        elif startNum // 10 == 4 and (len(number) == 13 or len(number) == 16):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")
