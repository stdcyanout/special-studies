import sys
def input():
    return sys.stdin.readline().strip()

def main():
    a, b = map(int, input().split())
    image = [[0] * b for i in range(a)]
    for i in range(a):
        image[i] = list(map(int, input().split()))
    c, d = map(int, input().split())
    martix = [[0] * d for i in range(c)]
    for i in range(c):
        martix[i] = list(map(int, input().split()))
    feature = [[0] * (a - c + 1) for i in range(b - d + 1)]
    for i in range(a - c + 1):
        for j in range(b - d + 1):
            for k in range(c):
                for m in range(d):
                    feature[i][j] += image[i + k][j + m] * martix[k][m]
    print(feature)
if __name__ == "__main__":
    main()