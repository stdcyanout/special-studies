import sys
def input():
    return sys.stdin.readline().strip()

row = []
column = []
block = []
num = []
solution = []
setted = [[False] * 10 for i in range(27)]
solved = False

def push(i, s):
    setted[row[i]][num[i]] = s
    setted[column[i]][num[i]] = s
    setted[block[i]][num[i]] = s

def solve(i):
    global solved
    if solved:
        return

    elif i == 81:
        for j in range(9):
            for k in range(9):
                print(num[9 * j + k], end = "")
            print()
        solved = True

    elif num[i] == 0:
        for j in range(1, 10):
            if not(setted[row[i]][j] or setted[column[i]][j] or setted[block[i]][j]):
                num[i] = j
                push(i, True)
                solve(i + 1)
                push(i, False)
                num[i] = 0

    else:
        solve(i + 1)

def main():
    for i in range(9):
        for j in range(9):
            row.append(i)
            column.append(j + 9)
            block.append(i // 3 * 3 + j // 3 + 18)
    s = input()
    for i in range(81):
        tmp = int(s[i])
        num.append(tmp)
        push(i, True)
    for i in range(9):
        for j in range(9):
            if num[9 * i + j] == 0:
                print(" ", end = "")
            else:
                print(num[9 * i + j], end = "")
        print()
    print("solution:")
    solve(0)

if __name__ == "__main__":
    main()