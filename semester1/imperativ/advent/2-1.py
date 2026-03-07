valid = 0

with open("2.in", "r") as f:
    for line in f:
        rule, word = line.split(": ")
        lr, letter = rule.split()
        letterrange = [int(x) for x in lr.split("-")]
        
        count = 0
        for l in word:
            if l == letter:
                count+=1

        if letterrange[0] <= count <= letterrange[1]:
            valid += 1




print(valid)
