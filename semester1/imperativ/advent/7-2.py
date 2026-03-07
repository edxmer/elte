
graph = dict()


with open("7.in", "r") as f:
    for line in f:
        outer_bag, inner_bags_raw = line.split(" bags contain ")
        inner_bags_raw = inner_bags_raw.rstrip(".").split(", ")
        inner_bags = []
        for x in inner_bags_raw:
            x = x.split()
            if not x[0] == "no":
                inner_bags.append((
                             " ".join(x[1:-1]),
                             int(x[0])
                        ))
        graph[outer_bag] = inner_bags
        

def count_bags(outer):
    count = 0
    for inner in graph[outer]:
        count += inner[1]
        count += inner[1] * count_bags(inner[0])
    return count

print(count_bags("shiny gold"))
