

class Vector2:
    def __init__ (self, x, y):
        self.x = x
        self.y = y

trees = 0

pos = Vector2(0, 0)

slope = Vector2(3, 1)

with open("3.in", "r") as f:
    road = [x.rstrip() for x in f.readlines()]
    
    
    
    while (pos.y < len(road)):
        if (road[pos.y][pos.x] == "#"):
            trees += 1
        print(road[pos.y], pos.x, pos.y)

        pos.y += slope.y
        pos.x += slope.x
        pos.x = pos.x % len(road[0])
        

print(trees)
