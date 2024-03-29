import sys
def input():
    return sys.stdin.readline().strip()

f = []

def solve(n):
    if f[n] == 0:
        if n == 0 or n == 1:
            f[n] = 1
        else:
            f[n] = solve(n-1) + solve(n-2)
        return f[n]
    else:
        return f[n]

def main():
    n = int(input())
    for i in range(n):
        f.append(0)
    solve(n - 1)
    print(f)

if __name__ == "__main__":
    main()