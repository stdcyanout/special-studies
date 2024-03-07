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
    n,m=map(int,getline().split())
    s=[]
    ans=[]
    for i in range(n):
        s.append(max(list(map(int,getline().split()))))
    solve=sum(s)
    print(solve)
    for i in s:
        if solve%i==0:
            ans.append(i)

    size=len(ans)
    if ans:
        for i in range(size):
            if i==size-1:
                print(ans[i],end='')
            else:
                print(ans[i],end=' ')
        print()
    else:
        print(-1)

if __name__ == "__main__":
    main()