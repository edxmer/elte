# Olvassunk be 0-9,a,b,c,d,e,f karaktereket (minden másra adjunk hibát). A beolvasott sorozatot értelmezzünk
# egy hexadecimális számként, majd konvertáljuk át 10-es számrendszerbe. Használd az ord/chr függvényeket

def hex_to_dec(char):
    if ord('0') <= ord(char) <= ord('9'):
        return ord(char) - ord('0')
    elif ord('a') <= ord(char) <= ord('f'):
        return ord(char) - ord('a') + 10
    else:
        raise ValueError("Ez nem egy hex szám.")

hex = input("Hex szám: ") # 1234ef

dec = 0


for i in range(len(hex)):
    helyiertek = len(hex) - i - 1 # ha len=6, akkor 5,4..0
    ertek = hex_to_dec(hex[i])

    dec += 16 ** helyiertek * ertek

print("A decimális értéke ", dec)

