

def get_seat_id(boarding_pass):

    row_pass = boarding_pass[0:7]
    column_pass = boarding_pass[7:10]
    
    row_low = 0
    row_high = 127
    
    for i in range(7):
        d = 2 ** (6-i)
        if row_pass[i] == "F": # lower half
            row_high -= d
        else:
            row_low += d
    
    row = row_low

    column_low = 0
    column_high = 7

    for i in range(3):
        d = 2 ** (2 - i)
        if column_pass[i] == "L": # lower half
            column_high -= d
        else:
            column_low += d

    
    column = column_low

    seat_id = row * 8 + column

    return seat_id


with open("5.in", "r") as f:
    print(get_seat_id(max(f.readlines(), key=get_seat_id)))
