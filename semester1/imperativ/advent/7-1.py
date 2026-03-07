
possible_colors = set()
graph = dict()


with open("7.in", "r") as f:
    for line in f:
        outer_bag, inner_bags = line.split(" bags contain ")
        inner_bags = inner_bags.rstrip(".").split(", ")
        inner_bags = [" ".join(x.split()[1:-1]) for x in inner_bags]


        for inner in inner_bags:
            if inner == "other": # no other bags
                pass
            elif inner in graph:
                graph[inner].append(outer_bag)
            else:
                graph[inner] = [outer_bag]

def walk_graph(inner):
    if inner in graph:
        for outer in graph[inner]:
            if not outer in possible_colors:
                possible_colors.add(outer)
                walk_graph(outer)
walk_graph("shiny gold")

print(len(possible_colors))
        
