# ascii helper to string printing in brainfuck

while(True):
    s = input("\n> ")
    match len(s):
        case 1: # single ascii
            print(f"{s}: {ord(s)}") 
        case 2: # ascii difference
            print(f"{s[0]} to {s[1]}: {ord(s[1]) - ord(s[0])}")
        case _:
            print("no output")
