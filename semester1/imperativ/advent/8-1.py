


NOP = 0
JMP = 1
ACC = 2
_INS={'nop':NOP, 'jmp':JMP, 'acc':ACC}

instructions = []

with open("8.in", "r") as f:
    for line in f:
        x = line.split()
        instructions.append((
                  _INS[x[0]],
                  int(x[1])
            ))

history = set()

accumulation = 0
current = 0

while not current in history:
    history.add(current)
    ins = instructions[current]
    if ins[0] == JMP:
        current += ins[1]
    elif ins[0] == ACC:
        accumulation += ins[1]
        current += 1
    else:
        current += 1

print(accumulation)
