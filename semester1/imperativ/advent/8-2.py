


NOP = 0
JMP = 1
ACC = 2
_INS={'nop':NOP, 'jmp':JMP, 'acc':ACC}

instructions = []

with open("8.in", "r") as f:
    for line in f:
        x = line.split()
        instructions.append([
                  _INS[x[0]],
                  int(x[1])
            ])

size = len(instructions)

def test_instructions():
    global instruction, NOP, JMP, ACC

    history = set()

    accumulation = 0
    current = 0
    
    last = False
    while not current in history and not last:
        last = current == size - 1
        history.add(current)
        ins = instructions[current]

        if ins[0] == JMP:
            current += ins[1]
        elif ins[0] == ACC:
            accumulation += ins[1]
            current += 1
        else:
            current += 1
    
    return last, accumulation

def swap(i):
    global instructions, NOP, JMP, ACC
    if instructions[i][0] == NOP:
        instructions[i][0] = JMP
    elif instructions[i][0] == JMP:
        instructions[i][0] = NOP


for i in range(size):
    swap(i)
    last, accumulation = test_instructions()
    swap(i)

    if last:
        print(accumulation)
