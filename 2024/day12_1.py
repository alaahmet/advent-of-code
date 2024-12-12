#!/usr/bin/env python3

with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    a = file.read().strip('\n').split('\n')

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

n = len(a)
m = len(a[0])
vis = [[0 for i in range(m)] for j in range(n)]

def check(x, y):
    return x >= 0 and x < n and y >= 0 and y < m


ans = 0
nodes = 0
adj = 0

def dfs(x, y):
    global nodes, adj
    if vis[x][y] == 1:
        return
    vis[x][y] = 1
    nodes += 1
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if check(nx, ny):
            if a[nx][ny] == a[x][y]:
                adj += 1
                if vis[nx][ny] == 0:
                    dfs(nx, ny)


for i in range(n):
    for j in range(m):
        if vis[i][j] == 0:
            nodes = 0
            adj = 0
            dfs(i, j)
            perimeter = nodes * 4 - adj
            ans += nodes * perimeter
            # print(nodes, perimeter)

print(ans)
