

with open("9.in", "r") as f:
    nums = [int(x.strip()) for x in f.readlines()]

invalid = 133015568


for i in range(len(nums)):
    for j in range(i):
        ls = nums[j:(i+1)]
        if sum(ls) == invalid:
            print(min(ls) + max(ls))
