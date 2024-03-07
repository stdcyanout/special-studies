import sys
def getline():
    return sys.stdin.readline().strip()

def main():
    s = getline()[::-1]
    ans = 0
    cnt = 0
    for c in s:
        cnt += 1
        if cnt % 2:
            ans += int(c)
        else:
            ans -= int(c)
    print(abs(ans))

if __name__=="__main__":
    main()