import sys
def input():
    return sys.stdin.readline().strip()

n, m = 0, 0
graph = []
vis = []
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
sm = 0

def check(i, j):
    global n, m, graph, vis, dy, dx, sm
    if i < 0 or i >= n:
        return False
    if j < 0 or j >= m:
        return False
    if vis[i][j]:
        return False
    return True

def dfs(y, x):
    global n, m, graph, vis, dy, dx, sm
    vis[y][x] = True
    sm += graph[y][x]
    for i in range(4):
        if check(y + dy[i], x + dx[i]):
            break
    else:
        return

    sy, sx = 1e6 + 1, 1e6 + 1
    for i in range(4):
        if check(y + dy[i], x + dx[i]):
            if sy == 1e6 + 1 and sx == 1e6 + 1:
                sy, sx = y + dy[i], x + dx[i]
            elif graph[y + dy[i]][x + dx[i]] < graph[sy][sx]:
                sy, sx = y + dy[i], x + dx[i]
    dfs(sy, sx)
    
def main():
    global n, m, graph, vis, dy, dx, sm
    n, m = map(int, input().split())
    vis = [[False] * m for i in range(n)]
    sy, sx = 0, 0
    for i in range(n):
        graph.append([])
        graph[i] = [int(j) for j in input().split()]
        for j in range(m):
            if graph[i][j] < graph[sy][sx]:
                sy, sx = i, j
    dfs(sy ,sx)
    print(sm)

if __name__ == "__main__":
    main()