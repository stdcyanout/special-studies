import sys
def input():
    return sys.stdin.readline().strip()

n, m = 0, 0
maze = []
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]
solution = 0

def printall():
    global n, m, maze, dy, dx, solution
    for i in maze:
        for j in i:
            print(j, end = " ")
        print()

def check(i, j):
    global n, m, maze, dy, dx, solution
    if i < 0 or i >= n:
        return False
    if j < 0 or j >= m:
        return False
    if maze[i][j] == 1 or maze[i][j] == 2:
        return False
    return True

def dfs(y, x):
    global n, m, maze, dy, dx, solution
    if y == n - 2 and x == m - 2:
        solution += 1
        print(f"solution#{solution}")
        printall()
        return
    
    for i in range(4):
        if check(y + dy[i], x + dx[i]):
            maze[y + dy[i]][x + dx[i]] = 1
            dfs(y + dy[i], x + dx[i])
            maze[y + dy[i]][x + dx[i]] = 0
    
def main():
    global n, m, maze, dy, dx, solution
    n, m = map(int, input().split())
    for i in range(n):
        maze.append([])
        maze[i] = [int(j) for j in input().split()]
    maze[1][1] = 1
    dfs(1, 1)

if __name__ == "__main__":
    main()