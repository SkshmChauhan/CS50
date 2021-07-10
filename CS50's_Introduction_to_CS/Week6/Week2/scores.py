# Averages three numbers using a list
# from cs50 import get_int

# Scores
scores = [72, 73, 33]
# Print average
print("Average: " + str(sum(scores) / len(scores)))
print(f"Average: {sum(scores) / len(scores)}")

# Getting user's input:
scores = []
for i in range(3):
    # scores.append(get_int("Score: "))
    scores.append(int(input("Score: ")))
# Print average
print(f"Average: {sum(scores) / len(scores)}")
