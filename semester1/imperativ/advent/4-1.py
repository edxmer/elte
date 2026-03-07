

def testinfo(e):
    testdata = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]
    for d in testdata:
        if not d in e:
            return 0
    return 1



valid = 0

with open("4.in", "r") as f:
    for entry in f.read().split("\n\n"):
        valid += testinfo(entry)


print(valid)

