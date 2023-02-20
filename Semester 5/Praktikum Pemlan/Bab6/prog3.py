from collections import Counter


def remov_duplicates(input):
    input = input.split(" ")

    for i in range(0, len(input)):
        input[i] = "".join(input[i])

    UniqW = Counter(input)
    s = " ".join(UniqW.keys())
    print(s)


if __name__ == "__main__":
    input = 'Python is great and Java is also great'
    remov_duplicates(input)