import json
import sys

sys.stdin = open("in.txt", "r")

# 輸入二維陣列大小
n, m = map(int, input().split())

# 初始化空 grid
grid = [[[] for _ in range(m + 1)] for _ in range(n + 1)]

# 遍歷上三角 (含對角線)
for r in range(1, n + 1):
    for c in range(1, m + 1):
        if r < c:
            continue  # r<c 不存資料
        t = int(input())
        tuples = []
        for _ in range(t):
            x, y, z = map(int, input().split())
            tuples.append((x, y, z))
        grid[r][c] = tuples

# 存成 JSON
with open("grid.json", "w") as f:
    json.dump(grid, f, indent=2)

print("儲存完成 grid.json")
