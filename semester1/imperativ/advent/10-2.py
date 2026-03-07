
with open("10.in", "r") as f:
    jolts = [int(x) for x in f.readlines()]


jolts.append(0)
jolts.sort()
jolts.append(jolts[-1] + 3)


arrangements = [0] * len(jolts)
arrangements[-1] = 1


for i in range(len(jolts))[::-1]:
    j = i+1
    while j < len(jolts) and jolts[j] - jolts[i] <= 3:
        arrangements[i] += arrangements[j]
        j+=1



print(arrangements[0])
