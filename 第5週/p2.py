import sys
def input():
    return sys.stdin.readline().strip()
INT_MIN = -2147483648
def main():
    a, b = map(int, input().split())
    image = [[0] * b for i in range(a)]
    for i in range(a):
        image[i] = list(map(int, input().split()))
    c, d = map(int, input().split())
    pool = [[INT_MIN] * (b // d) for i in range(a // c)]
    for i in range(a):
        for j in range(b):
            pool[i // c][j // d] = max(pool[i // c][j // d], image[i][j])
    print(pool)

if __name__ == "__main__":
    main()