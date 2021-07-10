# Good design
# print("meow")
# print("meow")
# print("meow")

# Better design
# for i in range(3):
#     print("meow")

def main():
    # for i in range(3):
    #     meow()
    meown(3)


# Meow once
def meow():
    print("meow")


# Meow some number of times
def meown(n):
    for i in range(n):
        print("meow")


if __name__ == "__main__":
    main()