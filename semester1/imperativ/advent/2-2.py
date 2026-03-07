valid = 0

with open("2.in", "r") as f:
    for line in f:
        rule, word = line.split(": ")
        lr, letter = rule.split()
        first, second = [int(x) - 1 for x in lr.split("-")]

        # important variables: word, letter, first, second
        
        x = (word[first] == letter) + (word[second] == letter)

        if x == 1:
            valid+=1

print(valid)
