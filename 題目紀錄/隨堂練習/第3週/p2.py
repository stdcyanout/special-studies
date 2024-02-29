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
    s=getline().lower()
    alpha=[0]*26
    for c in s:
        if c.isalpha():
            alpha[ord(c)-ord('a')]+=1
    for i in range(26):
        if alpha[i]:
            print(chr(ord('a')+i), alpha[i])

if __name__ == "__main__":
    main()