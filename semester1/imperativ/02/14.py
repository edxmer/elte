a = 2

if a % 2 == 0:
    print(" páros")
    print("  szám")

if 1 == 2:
    pass

c = "a"

if (c == "á" 
    or c == "é" 
    or c == "ű" 
    or c == "ú" 
    or c == "ő" 
    or c == "ó"):
    print("Hosszú magánhangzó")
else:
    print("Mássalhangzó vagy rövid magánhangzó")

maganhangzok = ["a", "e", "u", "i", "o", "ö", "é", "ü", "ő", "á", "ó", "ú", "ű"]

d = input()

if d in maganhangzok:
    print("yep")
else:
    print("nahhh")