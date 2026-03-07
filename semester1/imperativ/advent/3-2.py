
class Vector2:
    def __init__ (self, x, y):
        self.x = x
        self.y = y

with open("3.in", "r") as f:
    road = [x.rstrip() for x in f.readlines()]
    
    
def test_slope(x, y):
    trees = 0
    pos = Vector2(0, 0)
    slope = Vector2(x, y)
    while (pos.y < len(road)):
        if (road[pos.y][pos.x] == "#"):
            trees += 1
        print(road[pos.y], pos.x, pos.y)

        pos.y += slope.y
        pos.x += slope.x
        pos.x = pos.x % len(road[0])
    return trees

sol = test_slope(1, 1)
sol *= test_slope(3, 1)
sol *= test_slope(5, 1)
sol *= test_slope(7, 1)
sol *= test_slope(1, 2)

print(sol)
