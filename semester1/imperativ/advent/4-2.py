
from re import match

i = 1

def testdata(e):
    required = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}
    
    global i
    i+= 1

    data = {}

    fields = e.split()
    
    for field in fields:
        key, value = field.split(":")
        data[key] = value
    

    if (not required.issubset(data.keys())):
        return 0

    
    if ("in" in data['hgt']):
        data['hgt'] = int(data['hgt'].rstrip('in') )
        is_inches = True
    else:
        data['hgt'] = int(data['hgt'].rstrip('cm'))
        is_inches = False

        
    is_cm = not is_inches



    if  (
            1920 <= int(data['byr']) <= 2002 and
            2010 <= int(data['iyr']) <= 2020 and
            2020 <= int(data['eyr']) <= 2030 and
            (
                (150 <= data['hgt'] <= 193 and is_cm) or
                (59 <= data['hgt'] <= 76 and is_inches)
            ) and
            match(r"^#[0-9a-f]{6}$", data['hcl']) and
            data['ecl'] in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth'] and
            match(r"^[0-9]{9}$", data['pid'])
        ):
        return 1
    return 0



valid = 0

with open("4.in", "r") as f:
    for entry in f.read().strip().split("\n\n"):
        valid += testdata(entry)


print(valid)

