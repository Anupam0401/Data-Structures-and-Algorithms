print("Welcome to Sasta Hacking!")
print("Lets learn and master Caeser Cypher!\n")
str= input("Enter a string :  ")
print("Press D to decode or E to encode your string.\n")
op = input(": ")

def decode(str,shift) :
    s=""
    for c in str :
        char_shift = int(c+shift)
        if char_shift<=122:
            s=s.append(chr(char_shift))
        else:
            s=s.append(chr(char_shift-25))
    return s


if op=="D" or op=="d":
    print("Since you are decoding the string but you no idea about the shift that was initiallly useed to encode the same string so, we are gonna walk you through every possible outcome for the string.")
    print("I believe you are wise enough to figure out the correct decoded string that makes sense to you :)")
    print("The results shown below are in the following format : <shift> ... <decoded string>\n")
    for i in range(1,27):
        decoded = decode(str,i)
        print(decoded)

