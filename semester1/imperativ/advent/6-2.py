from string import ascii_lowercase

def get_letters(data):
    letters = set(ascii_lowercase)
    for line in data.split("\n"):
        letters = letters.intersection( set(line.strip()) )

    return len(letters)

with open("6.in", "r") as f:
    print(sum(map( get_letters, f.read().strip().split("\n\n") )))

