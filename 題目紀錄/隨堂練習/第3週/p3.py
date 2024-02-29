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
    alpha=[]
    for i in range(26):
        alpha.append([i,0])
    for c in s:
        if c.isalpha():
            alpha[ord(c)-ord('a')][1]+=1
    alpha.sort(reverse=True,key=lambda t:t[1])
    for i in range(26):
        if alpha[i][1]<alpha[0][1] or alpha[i][1]==0:
            break
        print(chr(alpha[i][0]+ord('a')),alpha[i][1])

if __name__ == "__main__":
    main()