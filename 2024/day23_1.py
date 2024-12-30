#!/usr/bin/env python3

with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    inp = [line.split('-') for line in file.read().strip().split('\n')]

g = {}
for (x, y) in inp:
    if x not in g:
        g[x] = []
    if y not in g:
        g[y] = []
    g[x].append(y)
    g[y].append(x)


triangles = set()

for a in g:
    for b in g[a]:
        for c in g[b]:
            if c in g[a]:
                triangles.add(tuple(sorted([a, b, c])))

ans = 0

for [t1, t2, t3] in triangles:
    if t1[0] == 't':
        ans += 1
    elif t2[0] == 't':
        ans += 1
    elif t3[0] == 't':
        ans += 1

print(ans)