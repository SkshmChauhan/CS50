def get_letters():
    chars = 0
    for char in s:
        if char.isalpha():
            chars += 1
    return chars


def get_words():
    wordcount = 0
    for i in range(0, len(s)):
        if s[i].isalpha() or s[i] == '-' or s[i] == chr(39):
            continue
        else:
            if s[i-1].isalpha():
                wordcount += 1
    return wordcount


def get_sentences():
    sentence_count = 0
    for char in s:
        if char == '.' or char == '!' or char == '?':
            sentence_count += 1
    return sentence_count


# Taking string input:
s = input("Text: ")

# Calling functions:
letters = get_letters()
words = get_words()
sentences = get_sentences()

# Printing the data:
# print("letters ", letters)
# print("words ", words)
# print("sentence ", sentences)

# Calculating L and S:
ll = (letters / words) * 100
ss = (sentences / words) * 100
# print("L: ", ll)
# print("S: ", ss)

index = (0.0588 * ll) - (0.296 * ss) - 15.8
# print("Index: ", index)

if index < 1:
    print("Before Grade 1")
elif index < 16:
    print("Grade ", round(index))
else:
    print("Grade 16+")
