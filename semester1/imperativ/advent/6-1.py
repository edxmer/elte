

def get_letters(data):
    letters = set()
    for e in data:
        letters = letters.union(e.strip())

    return len(letters)

with open("6.in", "r") as f:
    print(sum(map( get_letters, f.read().strip().split("\n\n") )))

