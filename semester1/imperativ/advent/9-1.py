

with open("9.in", "r") as f:
    nums = [int(x.strip()) for x in f.readlines()]

def test_ind(ind):
    global nums
    
    num = nums[ind]

    for i in range(ind-25, ind):
        for j in range(ind-25, ind):
            a = nums[i]
            b = nums[j]
            if a != b:
                if num == (a + b):
                    return False
    return True


found = False
i = 25
while not found and i < len(nums):
    if test_ind(i):
        print(nums[i])
        found = True
    else:
        i += 1
