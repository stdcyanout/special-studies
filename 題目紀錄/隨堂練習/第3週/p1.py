import sys
EOF = False
count = -1
data = [[]]
if EOF == False:
    data = sys.stdin.readlines()
def getline():
    if EOF == True:
        return sys.stdin.readline().strip()
    else:
        global count
        count += 1
        return data[count].strip()

def main():
    s=getline()
    lower=0
    upper=0
    for c in s:
        if c.isalpha():
            if c.islower():
                lower+=1
            else:
                upper+=1
    print(lower)
    print(upper)

if __name__ == "__main__":
    main()