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
v = []

def dfs(x, y):
    global nodes, adj
    if vis[x][y] == 1:
        return
    vis[x][y] = 1
    nodes += 1
    v.append((x, y))
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
            v.clear()
            dfs(i, j)
            sides = 0
            v.sort()
            assert nodes == len(v)

            last = (-1, -1)
            for (x, y) in v:
                if check(x - 1, y) and a[x - 1][y] == a[x][y]: continue
                elif x != last[0]:
                    sides += 1
                elif y != last[1] + 1:
                    sides += 1
                last = (x, y)

            last = (-1, -1)
            for (x, y) in v:
                if check(x + 1, y) and a[x + 1][y] == a[x][y]: continue
                elif x != last[0]:
                    sides += 1
                elif y != last[1] + 1:
                    sides += 1
                last = (x, y)        

            v.sort(key=lambda x: (x[1], x[0]))
            
            last = (-1, -1)
            for (x, y) in v:
                if check(x, y - 1) and a[x][y - 1] == a[x][y]: continue
                elif y != last[1]:
                    sides += 1
                elif x != last[0] + 1:
                    sides += 1
                last = (x, y)
            
            last = (-1, -1)
            for (x, y) in v:
                if check(x, y + 1) and a[x][y + 1] == a[x][y]: continue
                elif y != last[1]:
                    sides += 1
                elif x != last[0] + 1:
                    sides += 1
                last = (x, y)

            ans += nodes * sides
            # print(a[i][j], nodes, sides)
            
print(ans)
