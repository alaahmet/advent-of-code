#!/usr/bin/env python3

with open(('/home/ahmet/coding/advent-of-code/2024/a.in'), 'r') as file:
    arr = file.read().split('\n\n')
    a = [i.split('\n') for i in arr]

lock = []
key = []
n = 7
m = 5

for x in a:
    if x[0][0] == '#':
        aj = [0 for _ in range(5)]
        for j in range(m):
            for i in range(1, n):
                if x[i][j] == '#':
                    aj[j] += 1
                else: break
        lock.append((aj[0], aj[1], aj[2], aj[3], aj[4]))
    elif x[0][0] == '.':
        aj = [0 for _ in range(5)]
        for j in range(m):
            for i in range(n - 2, -1, -1):
                if x[i][j] == '#':
                    aj[j] += 1
                else: break
        key.append((aj[0], aj[1], aj[2], aj[3], aj[4]))

ans = 0

for x in key:
    for y in lock:
        if x[0] + y[0] <= 5 and x[1] + y[1] <= 5 and x[2] + y[2] <= 5 and x[3] + y[3] <= 5 and x[4] + y[4] <= 5:
            ans += 1

print(ans)