#!/usr/bin/env python3

with open('/home/ahmet/coding/advent-of-code/2024/a.in', 'r') as file:
    asx = file.read().strip().split('\n')
    arr = [int(i) for i in asx]

def mix(a, b):
    return a ^ b

def prune(a):
    return a % 16777216

def next_secret(x):
    x = prune(mix(x, x << 6))
    x = prune(mix(x, x >> 5))
    x = prune(mix(x, x << 11))
    return x

sum = 0
a = [[] for _ in range(len(arr))]

dp = [[[[0 for _ in range(20)] for _ in range(20)] for _ in range(20)] for _ in range(20)]

for idx in range(0, len(arr)):
    x = arr[idx]
    a[idx].append(x % 10)
    for i in range(2000):
        x = next_secret(x)
        a[idx].append(x % 10)
        # if(len(a[idx]) < 200): print(len(a[idx]), x % 10)

for i in range(0, len(arr)):
    vis = {}
    for j in range(4, len(a[i])):
        i1 = a[i][j - 3] - a[i][j - 4]
        i2 = a[i][j - 2] - a[i][j - 3]
        i3 = a[i][j - 1] - a[i][j - 2]
        i4 = a[i][j] - a[i][j - 1]
        if (i1 + 10, i2 + 10, i3 + 10, i4 + 10) not in vis:
            vis[(i1 + 10, i2 + 10, i3 + 10, i4 + 10)] = 1
            dp[i1 + 10][i2 + 10][i3 + 10][i4 + 10] += a[i][j]
        # if a[i][j - 4] == 6 and a[i][j - 3] == 4 and a[i][j - 2] == 5 and a[i][j - 1] == 4 and a[i][j] == 7:
        #     print(i, j, a[i][j], i1, i2, i3, i4)
        # if a[i][j - 4] == 8 and a[i][j - 3] == 6 and a[i][j - 2] == 7 and a[i][j - 1] == 6 and a[i][j] == 9:
        #     print(i, j, a[i][j], i1, i2, i3, i4)
        # if(j < 100): print(j, a[i][j])
        # if i1 == -2 and i2 == 1 and i3 == -1 and i4 == -3:
        #     print(i, j, a[i][j])
# 6 4 5 4 7
# 8 6 7 6 9
# print(dp[8][11][9][13])


max1, max2, max3, max4 = -1, -1, -1, -1
maxres = 0
for i in range(0, 20):
    for j in range(0, 20):
        for k in range(0, 20):
            for l in range(0, 20):
                if dp[i][j][k][l] > maxres:
                    maxres = dp[i][j][k][l]
                    max1, max2, max3, max4 = i, j, k, l

print(max1 - 10, max2 - 10, max3 - 10, max4 - 10)

print(dp[max1][max2][max3][max4])
