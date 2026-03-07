
with open("10.in", "r") as f:
    jolts = [int(x) for x in f.readlines()]
jolts.append(0)
jolts.sort()
jolts.append(jolts[-1] + 3)


diffs = [None, 0, 0, 0] 


for i in range(1, len(jolts)):
    diff = jolts[i] - jolts[i-1]
    diffs[diff]+=1

print(diffs[1] * diffs[3])
