


with open("1.in", "r") as f:
    lines = list(map(lambda x: int(x), f.readlines()))

for a in lines:
    for b in lines:
        if a + b == 2020:
            print(a*b)



