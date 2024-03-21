import sys
def input():
    return sys.stdin.readline().strip()

alpha = ['A', 'B', 'C']

def solve(n, a, b):
    if n > 1:
        solve(n - 1, a, 3 - a - b)
    print("從", alpha[a], "搬到", alpha[b])
    if n > 1:
        solve(n - 1, 3 - a - b, b)

def main():
    n = int(input())
    solve(n, 0, 2)

if __name__ == "__main__":
    main()