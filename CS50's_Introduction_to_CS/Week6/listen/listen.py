# Get input
words = input("Say something!\n").lower()
# Recognizes via text input

# Respond to input:
if "hello" in words:
    print("Hello to you too!")
elif "how are you" in words:
    print("I am well, thanks!")
elif "goodbye" in words:
    print("Goodbye to you too!")
else:
    print("Huh?")
