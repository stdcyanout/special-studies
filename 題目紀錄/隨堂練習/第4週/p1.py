import sys
def getline():
    return sys.stdin.readline().strip()

def main():
    s = getline()
    ans = 0
    for c in s:
        ans += int(c)
    print(ans)

if __name__=="__main__":
    main()