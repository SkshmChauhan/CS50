import csv
import sys


# Function return the longest continuous patter in provided sequence of the argument str
def getlongest(string):
    longest = 0
    count = 0
    i = 0
    while i < len(sequence):
        if i + len(string) < len(sequence):
            if sequence[i:i+len(string)] == string:
                count += 1
                i += len(string)
                continue
            else:
                if longest < count:
                    longest = count
                count = 0
        else:
            break
        i += 1
    if longest < count:
        longest = count
    # Returning longest value:
    return longest


if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.txt")
sequence = str()
# Reads DNA sequence into memory from file
with open(sys.argv[2]) as file:
    reader = csv.reader(file)
    for values in reader:
        # Stored DNA sequence in sequence
        sequence = values[0]

headers = []
details = []
with open(sys.argv[1]) as csvfile:
    reader = csv.reader(csvfile)
    val = 0
    for values in reader:
        # Checking for first row:
        if val == 0:
            val = 1
            # Storing different types of STRs in headers list:
            headers = values
            continue
        else:
            # Adding rest of the details of person from CSV in details list:
            details.append(values)
headers.__delitem__(0)


result = []
# Iterating over each STR and computing its value in sequence provided
for value in headers:
    answer = getlongest(value)
    # Adding obtained values in result list:
    result.append(answer)


flag = False
# Iterating over each person from details list:
for person in details:
    # Iterating and matching each value from results list to person's details:
    for pos in range(0, len(result)):
        if int(person[pos + 1]) == result[pos]:
            flag = True
            continue
        else:
            flag = False
            break
    if flag:
        # If match, printing person's name:
        print(person[0])
        sys.exit(0)
    else:
        continue
# Person not found:
print("No match")
sys.exit(0)
