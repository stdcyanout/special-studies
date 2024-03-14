import sys
def getline():
    return sys.stdin.readline().strip()

def main():
    n = int(getline())
    s = list(getline().split())
    ans = [[0]*2 for i in range(n)]
    for i in range(n):
        ans[i][1] = int(s[i])
        for c in s[i]:
            ans[i][0] += int(c)
    mx = max(ans)
    print(mx[1])
    print(mx[0])

if __name__=="__main__":
    main()