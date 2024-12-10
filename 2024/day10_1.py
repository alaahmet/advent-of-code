#!/usr/bin/env python3

with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    data = file.read().strip()
    grid = data.split('\n')
    grid = [[int(char) for char in line] for line in grid]

n = len(grid)
m = len(grid[0])

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def check(x, y):
    return 0 <= x < n and 0 <= y < m

vis = []

def dfs(x, y):
    global score
    vis[x][y] = 1
    if grid[x][y] == 9:
        score += 1
        return
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if check(nx, ny) and grid[nx][ny] == grid[x][y] + 1 and not vis[nx][ny]:
            dfs(nx, ny)
    return

ans = 0
for i in range(n):
    for j in range(m):
        if grid[i][j] == 0:
            vis = [[0] * m for _ in range(n)]
            score = 0
            dfs(i, j)
            ans += score

print(ans)